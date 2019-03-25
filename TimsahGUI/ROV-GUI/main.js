const { app, BrowserWindow } = require('electron')
const path = require('path')
const url = require('url')

let win

function createWindow () {
  win = new BrowserWindow({ width: 800, height: 600, frame: true, webPreferences: {webSecurity: false}})

  // and load the index.html of the app.
  win.loadURL(url.format({
    pathname: path.join(__dirname, './renderer/index.html'),
    protocol: 'file:',
    slashes: true
  }))

  // Open the DevTools.
  //win.webContents.openDevTools()

  // Emitted when the window is closed.
  win.on('closed', () => {
    win = null
  })
}

app.on('ready', createWindow)
