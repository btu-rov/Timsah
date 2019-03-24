
const SerialPort = require('serialport')
const Readline = require('@serialport/parser-readline')
const port = new SerialPort('COM7', {
  baudRate: 9600
})

const parser = port.pipe(new Readline({ delimiter: '\n' }))

parser.on('data', function(data) {
  console.log("Data: " + data);
})
