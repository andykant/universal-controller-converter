var serialport = require('serialport'),
  colors = require('colors'),
  util = require('util');
  
colors.setTheme({
  warn: 'yellow',
  debug: 'blue',
  error: 'red',
  off: 'red',
  on: 'green'
});

var buttons = {
    // up: '⬆',
    // down: '⬇',
    // left: '⬅',
    // right: '➡'
  },
  value = function(name, value) {
    return (buttons[name] || name)[value ? 'on' : 'off'];
  };

var arduino = new serialport.SerialPort('/dev/tty.usbmodemfa131', {
  baudrate: 9600,
  parser: serialport.parsers.readline("\n") 
});

arduino.on('data', function(data) {
  try {
    var input = eval("("+data+")");
    if (input) {
      var data = input.data;
      util.print(input.type.debug + ' ');
      ['a','b','select','start','up','down','left','right'].forEach(function(button) {
        util.print(value(button, data[button]) + ' ');
      });
      util.print('powerpad:'.debug);
      for (var i = 0; i < data.powerpad.length; i++) {
        util.print(value('o', data.powerpad[i]));
      }
      util.puts('');
    }
  } catch(e) { util.puts(data.grey); }
});