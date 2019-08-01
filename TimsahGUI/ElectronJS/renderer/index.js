// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// All of the Node.js APIs are available in this process.

const SerialPort = require('serialport')
const Readline = require('@serialport/parser-readline')

var Chart = require('chart.js');

const port = new SerialPort('COM3', {
  baudRate: 9600
})

const parser = port.pipe(new Readline({
  delimiter: '\n'
}))

let status = 0
let config = 0
let mode = ''
let count = 0
let parsedData
let dataReady = 0

// Strings
let rovTMP = ''
let rovGYR = ''
let rovACC = ''
let rovTLT = ''
let rovSPD = ''
let rovSON = ''

// Integers
let rovGYRdata = []
let rovACCdata = []
let rovTLTdata = []
let rovSPDdata = []
let rovSONdata = []
let rovTMPdata


// Final data
let GYRdata = []
let ACCdata = []
let TLTdata = []
let SPDdata = []
let SONdata = []
let TMPdata

parser.on('data', function(data) {
  // Print all received data to #incomingData text area.
  //document.getElementById("incomingData").value = data;

  if (data == '$') {
    status = 1 // next data will be mode
    mode = ''
  }
  // The command # means end of mode
  else if (data == '#' && mode == 'ACC') {
    status = 0
    rovACC = '' // Clear ACC data befor write
  } else if (data == '#' && mode == 'GYR') {
    status = 0
    rovGYR = '' // Clear GYR data befor write
  } else if (data == '#' && mode == 'TMP') {
    status = 0
    rovTMP = '' // Clear TMP data befor write
  }else if (data == '#' && mode == 'SPD') {
    status = 0
    rovSPD = '' // Clear SPD data befor write
  }else if (data == '#' && mode == 'SON') {
    status = 0
    rovSON = '' // Clear SON data befor write
  }else if (data == '#' && mode == 'TLT') {
    status = 0
    rovTLT = '' // Clear TLT data befor write
  }

  // If end of data command ($$) received then print all data.
  else if (data == '$$') {
    document.getElementById('TMP').innerHTML = "TMP Data: " + rovTMP
    document.getElementById('GYR').innerHTML = "GYR Data: " + rovGYR
    document.getElementById('ACC').innerHTML = "ACC Data: " + rovACC
    document.getElementById('TLT').innerHTML = "TLT Data: " + rovTLT
    document.getElementById('SPD').innerHTML = "SPD Data: " + rovSPD
    document.getElementById('SON').innerHTML = "SON Data: " + rovSON
  }
  // Get Mode
  else if (status == 1) {
    mode += data
  }
  // Get Data
  else if (status == 0) {
    if (mode == 'ACC') {
      rovACC += data
      rovACC += ','
      parsedData = parseInt(data, 10)
      rovACCdata[count] = parsedData
      count++
      if(count == 3) {
        ACCdata = rovACCdata
        count = 0;
      }
    }
    if (mode == 'GYR') {
      rovGYR += data
      rovGYR += ','
      parsedData = parseInt(data, 10)
      rovGYRdata[count] = parsedData
      count++;
      if(count == 3) {
        GYRdata = rovGYRdata
        count = 0;
      }
    }
    if (mode == 'TLT') {
      rovTLT += data
      rovTLT += ','
      parsedData = parseInt(data, 10)
      rovTLTdata[count] = parsedData
      count++;
      if(count == 3) {
        TLTdata = rovTLTdata
        count = 0;
      }
    }
    if (mode == 'TMP') {
      rovTMP = data
      parsedData = parseInt(data, 10)
      rovTMPdata = parsedData
    }
    if (mode == 'SPD') {
      rovSPD += data
      rovSPD += ','
      parsedData = parseInt(data, 10)
      rovSPDdata[count] = parsedData
      count++
      if(count == 1) {
        SPDdata = rovSPDdata
        count = 0;
      }
    }
    if (mode == 'SON') {
      rovSON += data
      rovSON += ','
      parsedData = parseInt(data, 10)
      rovSONdata[count] = parsedData
      count++
      if(count == 4) {
        SONdata = rovSONdata
        count = 0;
      }
    }
  }
})

var chartDataTemp = [];
var ctxTemp = document.getElementById('temp');
var chartTemp = new Chart(ctxTemp, {
  type: 'line',
  data: {
    labels: ['-10', '-9', '-8', '-7', '-6', '-5', '-4', '-3', '-2', '-1', '0'],
    datasets: [{
      label: 'TMP',
      data: chartDataTemp,
      fill: true,
      backgroundColor: "rgba(99, 132, 255, 0.2)",
      borderColor: "rgb(99, 132, 255)",
      pointBackgroundColor: "rgb(99, 132, 255)",
    }]
  },
  options: {
    scales: {
      yAxes: [{
        ticks: {
          min: 20,
          max: 50,
          beginAtZero: true
        }
      }]
    }
  }
});

var chartDataAcc = []
var ctxAcc = document.getElementById('acc');
var chartAcc = new Chart(ctxAcc, {
  type: 'radar',
  data: {
    labels: ['+y', '+x', '-y', '-x'],
    datasets: [{
      label: 'ACC',
      data: chartDataAcc,
      fill: true,
      backgroundColor: "rgba(255, 99, 132, 0.2)",
      borderColor: "rgb(255, 99, 132)",
      pointBackgroundColor: "rgb(255, 99, 132)",
    },{
      label: '',
      data: [100, 100, 100, 100],
      fill: false,
      backgroundColor: "rgba(0, 0, 0, 0)",
      borderColor: "rgba(0, 0, 0, 0)",
      pointBackgroundColor: "rgba(0, 0, 0, 0)"
    }]
  },
  options: {
    elements: {
      line: {
        tension: 0,
        borderWidth: 3
      }
    }
  }
});

var chartDataGyr = []
var ctxGyr = document.getElementById('gyr');
var chartGyr = new Chart(ctxGyr, {
  type: 'radar',
  data: {
    labels: ['+y', '+x', '-y', '-x'],
    datasets: [{
      label: 'GYR',
      data: chartDataGyr,
      fill: true,
      backgroundColor: "rgba(132, 99, 255, 0.2)",
      borderColor: "rgb(132, 99, 255)",
      pointBackgroundColor: "rgb(132, 99, 255)",
    },{
      label: '',
      data: [100, 100, 100, 100],
      fill: false,
      backgroundColor: "rgba(0, 0, 0, 0)",
      borderColor: "rgba(0, 0, 0, 0)",
      pointBackgroundColor: "rgba(0, 0, 0, 0)"
    }]
  },
  options: {
    elements: {
      line: {
        tension: 0,
        borderWidth: 3
      }
    }
  }
});

var chartDataTilt = []
var ctxTilt = document.getElementById('tlt');
var chartTilt = new Chart(ctxTilt, {
  type: 'radar',
  data: {
    labels: ['+y', '+x', '-y', '-x'],
    datasets: [{
      label: 'TLT',
      data: chartDataTilt,
      fill: true,
      backgroundColor: "rgba(24, 214, 210, 0.2)",
      borderColor: "rgb(24, 214, 210)",
      pointBackgroundColor: "rgb(24, 214, 210)",
    },{
      label: '',
      data: [100, 100, 100, 100],
      fill: false,
      backgroundColor: "rgba(0, 0, 0, 0)",
      borderColor: "rgba(0, 0, 0, 0)",
      pointBackgroundColor: "rgba(0, 0, 0, 0)"
    }]
  },
  options: {
    elements: {
      line: {
        tension: 0,
        borderWidth: 3
      }
    }
  }
});

var chartDataSpdR = []
var ctxSpdR = document.getElementById('speedRight');
var chartSpdR = new Chart(ctxSpdR, {
  type: 'doughnut',
  data: {
    datasets: [{
      data: chartDataSpdR,
      backgroundColor: [
        "rgba(125, 243, 80, 0.3)",
        "rgb(255, 255, 255)"
      ],
      borderColor: "rgb(125, 243, 80)",
      weight: 2
    }]
  },
  options: {
    cutoutPercentage: 70,
    circumference: 1.6*Math.PI,
    rotation: -1.3*Math.PI
  }
});

var chartDataSpdL = []
var ctxSpdL = document.getElementById('speedLeft');
var chartSpdL = new Chart(ctxSpdL, {
  type: 'doughnut',
  data: {
    datasets: [{
      data: chartDataSpdL,
      backgroundColor: [
        "rgba(80, 194, 169, 0.3)",
        "rgb(255, 255, 255)"
      ],
      borderColor: "rgb(80, 194, 169)",
      weight: 2
    }]
  },
  options: {
    cutoutPercentage: 70,
    circumference: 1.6*Math.PI,
    rotation: -1.3*Math.PI
  }
});

var chartDataSpdTopR = []
var ctxSpdTopR = document.getElementById('speedTopRight');
var chartSpdTopR = new Chart(ctxSpdTopR, {
  type: 'doughnut',
  data: {
    datasets: [{
      data: chartDataSpdTopR,
      backgroundColor: [
        "rgba(32, 32, 242, 0.3)",
        "rgb(255, 255, 255)"
      ],
      borderColor: "rgb(32, 32, 242)",
      weight: 2
    }]
  },
  options: {
    cutoutPercentage: 70,
    circumference: 1.6*Math.PI,
    rotation: -1.3*Math.PI
  }
});

var chartDataSpdTopL = []
var ctxSpdTopL = document.getElementById('speedTopLeft');
var chartSpdTopL = new Chart(ctxSpdTopL, {
  type: 'doughnut',
  data: {
    datasets: [{
      data: chartDataSpdTopL,
      backgroundColor: [
        "rgba(248, 2, 127, 0.3)",
        "rgb(255, 255, 255)"
      ],
      borderColor: "rgb(248, 2, 127)",
      weight: 2
    }]
  },
  options: {
    cutoutPercentage: 70,
    circumference: 1.6*Math.PI,
    rotation: -1.3*Math.PI
  }
});

var chartDataDepth = []
var ctxDepth = document.getElementById('depth');
var chartDepth = new Chart(ctxDepth, {
  type: 'bar',
  data: {
    labels: ["Depth", "Sonar 1", "Sonar 2", "Sonar Front"],
    datasets: [{
      label: "Depth",
      data: chartDataDepth,
      fill: false,
      backgroundColor: ["rgba(255, 99, 132, 0.2)", "rgba(255, 159, 64, 0.2)",
                        "rgba(23, 200, 101, 0.2)", "rgba(19, 82, 96, 0.2)"],
      borderColor: ["rgb(255, 99, 132)", "rgb(255, 159, 64)",
                    "rgb(23, 200, 101)", "rgb(19, 82, 96)"],
      borderWidth: 1
    }]
  },
  options: {
    scales: {
      xAxes: [{
        ticks: {
          beginAtZero: true
        }
      }],
      yAxes: [{
        ticks: {
          beginAtZero: true
        }
      }]
    }
  }
});

// Repeated every 1.5 seconds
setInterval(function(){
  for (var i = 0; i < chartDataTemp.length-1; i++) {
    chartDataTemp[i] = chartDataTemp[i+1]
  }
  chartDataTemp[15] = rovTMPdata
  chartTemp.update()
}, 1500)

// Repeads every 0.5 seconds
setInterval(function(){
  if (ACCdata[0] < 0 && ACCdata[1] < 0) {
    chartDataAcc = [0, 0, -ACCdata[1], -ACCdata[0]]
  }else if (ACCdata[0] > 0 && ACCdata[1] < 0) {
    chartDataAcc = [0, ACCdata[0], -ACCdata[1], 0]
  }else if (ACCdata[0] < 0 && ACCdata[1] > 0) {
    chartDataAcc = [ACCdata[1], 0, 0, -ACCdata[0]]
  }else {
    chartDataAcc = [ACCdata[1], ACCdata[0], 0, 0]
  }

  chartAcc.data.datasets[0].data = chartDataAcc
  chartAcc.update()

  if (GYRdata[0] < 0 && GYRdata[1] < 0) {
    chartDataGyr = [0, 0, -GYRdata[1], -GYRdata[0]]
  }else if (GYRdata[0] > 0 && GYRdata[1] < 0) {
    chartDataGyr = [0, GYRdata[0], -GYRdata[1], 0]
  }else if (GYRdata[0] < 0 && GYRdata[1] > 0) {
    chartDataGyr = [GYRdata[1], 0, 0, -GYRdata[0]]
  }else {
    chartDataGyr = [GYRdata[1], GYRdata[0], 0, 0]
  }

  chartGyr.data.datasets[0].data = chartDataGyr
  chartGyr.update()

  if (TLTdata[0] < 0 && TLTdata[1] < 0) {
    chartDataTilt = [0, 0, -TLTdata[1], -TLTdata[0]]
  }else if (TLTdata[0] > 0 && TLTdata[1] < 0) {
    chartDataTilt = [0, TLTdata[0], -TLTdata[1], 0]
  }else if (TLTdata[0] < 0 && TLTdata[1] > 0) {
    chartDataTilt = [TLTdata[1], 0, 0, -TLTdata[0]]
  }else {
    chartDataTilt = [TLTdata[1], TLTdata[0], 0, 0]
  }

  chartTilt.data.datasets[0].data = chartDataTilt
  chartTilt.update()

  chartDataSpdR = [SPDdata[0], 100-SPDdata[0]]
  chartSpdR.data.datasets[0].data = chartDataSpdR
  chartSpdR.update()

  chartDataSpdL = [SPDdata[1], 100-SPDdata[1]]
  chartSpdL.data.datasets[0].data = chartDataSpdTopL
  chartSpdL.update()

  chartDataSpdTopR = [SPDdata[2], 100-SPDdata[2]]
  chartSpdTopR.data.datasets[0].data = chartDataSpdTopR
  chartSpdTopR.update()

  chartDataSpdTopL = [SPDdata[3], 100-SPDdata[3]]
  chartSpdTopL.data.datasets[0].data = chartDataSpdTopL
  chartSpdTopL.update()

  chartDataDepth = [rovSONdata[0], rovSONdata[1], rovSONdata[2], rovSONdata[3], 400]
  chartDepth.data.datasets[0].data = chartDataDepth
  chartDepth.update()
}, 500)

/*
// If #btn clicked then send value of #sendDat input.
document.getElementById("btn").onclick = function(e) {
  let dat = document.getElementById("sendDat").value;
  document.getElementById('sendDat').value = ""
  port.write(dat);
};
*/
