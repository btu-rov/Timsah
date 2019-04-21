// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// All of the Node.js APIs are available in this process.

const SerialPort = require('serialport')
const Readline = require('@serialport/parser-readline')

var Chart = require('chart.js');

const port = new SerialPort('COM7', {
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
let rovSPD = ''
let rovSON = ''

// Integers
let rovGYRdata = []
let rovACCdata = []
let rovSPDdata = []
let rovTMPdata
let rovSONdata


// Final data
let GYRdata = []
let ACCdata = []
let SPDdata = []
let SONdata
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
  }

  // If end of data command ($$) received then print all data.
  else if (data == '$$') {
    document.getElementById('TMP').innerHTML = "TMP Data: " + rovTMP
    document.getElementById('GYR').innerHTML = "GYR Data: " + rovGYR
    document.getElementById('ACC').innerHTML = "ACC Data: " + rovACC
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
      if(count == 2) {
        SPDdata = rovSPDdata
        count = 0;
      }
    }
    if (mode == 'SON') {
      rovSON = data
      parsedData = parseInt(data, 10)
      rovSONdata = parsedData
    }
  }


})

var data1 = [];
var ctx1 = document.getElementById('temp');
var myChart1 = new Chart(ctx1, {
  type: 'line',
  data: {
    labels: ['-15', '-14', '-13', '-12', '-11', '-10', '-9', '-8', '-7',
    '-6', '-5', '-4', '-3', '-2', '-1', '0'],
    datasets: [{
      label: 'TMP',
      data: data1,
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

var data2 = []
var ctx2 = document.getElementById('acc');
var myChart2 = new Chart(ctx2, {
  type: 'radar',
  data: {
    labels: ['+y', '+x', '-y', '-x'],
    datasets: [{
      label: 'ACC',
      data: data2,
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

var data3 = []
var ctx3 = document.getElementById('gyr');
var myChart3 = new Chart(ctx3, {
  type: 'radar',
  data: {
    labels: ['+y', '+x', '-y', '-x'],
    datasets: [{
      label: 'GYR',
      data: data3,
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

var data4 = []
var ctx4 = document.getElementById('speedX');
var myChart4 = new Chart(ctx4, {
  type: 'doughnut',
  data: {
    datasets: [{
      data: data4,
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

var data5 = []
var ctx5 = document.getElementById('speedY');
var myChart5 = new Chart(ctx5, {
  type: 'doughnut',
  data: {
    datasets: [{
      data: data5,
      backgroundColor: [
        "rgba(50, 200, 200, 0.3)",
        "rgb(255, 255, 255)"
      ],
      borderColor: "rgb(50, 200, 200)",
      weight: 2
    }]
  },
  options: {
    cutoutPercentage: 70,
    circumference: 1.6*Math.PI,
    rotation: -1.3*Math.PI
  }
});

var data6 = []
var ctx6 = document.getElementById('depth');
var myChart6 = new Chart(ctx6, {
  type: 'bar',
  data: {
    labels: ["Depth"],
    datasets: [{
      label: "Depth",
      data: data6,
      fill: false,
      backgroundColor: ["rgba(255, 99, 132, 0.2)", "rgba(255, 159, 64, 0.2)"],
      borderColor: ["rgb(255, 99, 132)", "rgb(255, 159, 64)"],
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
  for (var i = 0; i < data1.length-1; i++) {
    data1[i] = data1[i+1]
  }
  data1[15] = rovTMPdata
  myChart1.update()
}, 1500)

// Repeads every 0.5 seconds
setInterval(function(){
  if (GYRdata[0] < 0 && GYRdata[1] < 0) {
    data2 = [0, 0, -GYRdata[1], -GYRdata[0]]
  }else if (GYRdata[0] > 0 && GYRdata[1] < 0) {
    data2 = [0, GYRdata[0], -GYRdata[1], 0]
  }else if (GYRdata[0] < 0 && GYRdata[1] > 0) {
    data2 = [GYRdata[1], 0, 0, -GYRdata[0]]
  }else {
    data2 = [GYRdata[1], GYRdata[0], 0, 0]
  }

  myChart2.data.datasets[0].data = data2
  myChart2.update()

  if (ACCdata[0] < 0 && ACCdata[1] < 0) {
    data3 = [0, 0, -ACCdata[1], -ACCdata[0]]
  }else if (ACCdata[0] > 0 && ACCdata[1] < 0) {
    data3 = [0, ACCdata[0], -ACCdata[1], 0]
  }else if (ACCdata[0] < 0 && ACCdata[1] > 0) {
    data3 = [ACCdata[1], 0, 0, -ACCdata[0]]
  }else {
    data3 = [ACCdata[1], ACCdata[0], 0, 0]
  }

  myChart3.data.datasets[0].data = data3
  myChart3.update()

  data4 = [SPDdata[0], 100-SPDdata[0]]
  myChart4.data.datasets[0].data = data4
  myChart4.update()

  data5 = [SPDdata[1], 100-SPDdata[1]]
  myChart5.data.datasets[0].data = data5
  myChart5.update()

  data6 = [rovSONdata, 400]
  myChart6.data.datasets[0].data = data6
  myChart6.update()
}, 500)


// If #btn clicked then send value of #sendDat input.
document.getElementById("btn").onclick = function(e) {
  let dat = document.getElementById("sendDat").value;
  document.getElementById('sendDat').value = ""
  port.write(dat);
};
