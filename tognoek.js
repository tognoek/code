const robot = require("robotjs");

console.log("Start");
setTimeout(() => {
  console.log("Begin");
  const message = "Chéo";
  robot.typeStringDelayed(message, 100);
  robot.keyTap("enter");
}, 15000);
