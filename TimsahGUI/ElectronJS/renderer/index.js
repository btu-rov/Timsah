// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// All of the Node.js APIs are available in this process.

const SerialPort = require('serialport')
const Readline = require('@serialport/parser-readline')

var Chart = require('chart.js');
var data1 = [27, 28, 30, 29, 33, 34, 37, 40, 35]
var ctx1 = document.getElementById('temp');
var myChart = new Chart(ctx1, {
    type: 'line',
    data: {
      labels: ['0', '1', '2', '3', '4', '5', '6', '7', '8'],
      datasets: [{
        label: 'Temperature',
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
            beginAtZero: true
          }
        }]
      }
    }
});

var data2 = [50, 100, 30, 70]
var ctx2 = document.getElementById('acc');
var myChart = new Chart(ctx2, {
    type: 'radar',
    data: {
      labels: ['0', '1', '2', '3'],
      datasets: [{
        label: 'Acc',
        data: data2,
        fill: true,
        backgroundColor: "rgba(255, 99, 132, 0.2)",
        borderColor: "rgb(255, 99, 132)",
        pointBackgroundColor: "rgb(255, 99, 132)",
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

var data3 = [50, 100, 30, 70]
var ctx3 = document.getElementById('gyr');
var myChart = new Chart(ctx3, {
    type: 'radar',
    data: {
      labels: ['0', '1', '2', '3'],
      datasets: [{
        label: 'Gyr',
        data: data2,
        fill: true,
        backgroundColor: "rgba(132, 99, 255, 0.2)",
        borderColor: "rgb(132, 99, 255)",
        pointBackgroundColor: "rgb(132, 99, 255)",
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

  const port = new SerialPort('COM7', {
    baudRate: 9600
  })

  const parser = port.pipe(new Readline({ delimiter: '\n' }))

  let status = 0
  let config = 0
  let mode = ''
  let rovTMP = ''
  let rovGYR = ''
  let rovACC = ''

  parser.on('data', function(data) {
    // Print all received data to #incomingData text area.
    document.getElementById("incomingData").value += "\n"+data;

    if(data == '$') {
      status = 1 // next data will be mode
      mode = ''
    }
    // The command # means end of mode
    else if(data == '#' && mode == 'ACC') {
      status = 0
      rovACC = '' // Clear ACC data befor write
    }
    else if(data == '#' && mode == 'GYR') {
      status = 0
      rovGYR = '' // Clear GYR data befor write
    }
    else if(data == '#' && mode == 'TMP') {
      status = 0
      rovTMP = '' // Clear TMP data befor write
    }
    // If end of data command ($$) received then print all data.
    else if(data == '$$') {
      document.getElementById('TMP').innerHTML = "TMP Data: " + rovTMP
      document.getElementById('GYR').innerHTML = "GYR Data: " + rovGYR
      document.getElementById('ACC').innerHTML = "ACC Data: " + rovACC
    }
    // Get Mode
    else if(status == 1) {
      mode += data
    }
    // Get Data
    else if(status == 0) {
      if(mode == 'ACC') {
        rovACC += data
        rovACC += ','
      }
      if(mode == 'GYR') {
        rovGYR += data
        rovGYR += ','
      }
      if(mode == 'TMP') {
        rovTMP = data
      }
    }
  })

  // If #btn clicked then send value of #sendDat input.
  document.getElementById("btn").onclick = function(e) {
    let dat = document.getElementById("sendDat").value;
    document.getElementById('sendDat').value = ""
    port.write(dat);
  };
