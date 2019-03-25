// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// All of the Node.js APIs are available in this process.

const SerialPort = require('serialport')
const Readline = require('@serialport/parser-readline')

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
