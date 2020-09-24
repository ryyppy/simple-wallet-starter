// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");

function Icon$Clipboard(Props) {
  var classNameOpt = Props.className;
  var className = classNameOpt !== undefined ? classNameOpt : "";
  return React.createElement("svg", {
              className: "stroke-current " + className,
              height: "24",
              width: "24",
              fill: "none",
              strokeLinecap: "round",
              strokeLinejoin: "round",
              strokeWidth: "2",
              viewBox: "0 0 24 24"
            }, React.createElement("path", {
                  d: "M16 4h2a2 2 0 012 2v14a2 2 0 01-2 2H6a2 2 0 01-2-2V6a2 2 0 012-2h2"
                }), React.createElement("rect", {
                  height: "4",
                  width: "8",
                  rx: "1",
                  ry: "1",
                  x: "8",
                  y: "2"
                }));
}

var Clipboard = {
  make: Icon$Clipboard
};

function Icon$Copy(Props) {
  var classNameOpt = Props.className;
  var className = classNameOpt !== undefined ? classNameOpt : "";
  return React.createElement("svg", {
              className: "stroke-current " + className,
              height: "24",
              width: "24",
              fill: "none",
              strokeLinecap: "round",
              strokeLinejoin: "round",
              strokeWidth: "2",
              viewBox: "0 0 24 24"
            }, React.createElement("rect", {
                  height: "13",
                  width: "13",
                  rx: "2",
                  ry: "2",
                  x: "9",
                  y: "9"
                }), React.createElement("path", {
                  d: "M5 15H4a2 2 0 01-2-2V4a2 2 0 012-2h9a2 2 0 012 2v1"
                }));
}

var Copy = {
  make: Icon$Copy
};

function Icon$UpDownArrow(Props) {
  var classNameOpt = Props.className;
  var className = classNameOpt !== undefined ? classNameOpt : "";
  return React.createElement("svg", {
              height: "10",
              width: "18",
              fill: "none",
              viewBox: "0 0 18 10"
            }, React.createElement("path", {
                  className: "stroke-current " + className,
                  d: "M4.203 8.595V1.688M.75 5.141l3.453-3.453 3.454 3.453M13.796 1.688v6.907M17.25 5.141l-3.454 3.454-3.453-3.454",
                  strokeLinecap: "round",
                  strokeLinejoin: "round",
                  strokeWidth: "1.5"
                }));
}

var UpDownArrow = {
  make: Icon$UpDownArrow
};

function Icon$ArrowUp(Props) {
  var classNameOpt = Props.className;
  var className = classNameOpt !== undefined ? classNameOpt : "";
  return React.createElement("svg", {
              className: "stroke-current " + className,
              height: "24",
              width: "24",
              fill: "none",
              strokeLinecap: "round",
              strokeLinejoin: "round",
              strokeWidth: "2",
              viewBox: "0 0 24 24"
            }, React.createElement("path", {
                  d: "M12 19V5M5 12l7-7 7 7"
                }));
}

var ArrowUp = {
  make: Icon$ArrowUp
};

function Icon$ArrowDown(Props) {
  var classNameOpt = Props.className;
  var className = classNameOpt !== undefined ? classNameOpt : "";
  return React.createElement("svg", {
              className: "stroke-current " + className,
              height: "24",
              width: "24",
              fill: "none",
              strokeLinecap: "round",
              strokeLinejoin: "round",
              strokeWidth: "2",
              viewBox: "0 0 24 24"
            }, React.createElement("path", {
                  d: "M12 5v14M19 12l-7 7-7-7"
                }));
}

var ArrowDown = {
  make: Icon$ArrowDown
};

function Icon$VerticalDots(Props) {
  var classNameOpt = Props.className;
  var className = classNameOpt !== undefined ? classNameOpt : "";
  return React.createElement("svg", {
              className: "stroke-current " + className,
              height: "24",
              width: "24",
              fill: "none",
              stroke: "currentColor",
              strokeLinecap: "round",
              strokeLinejoin: "round",
              strokeWidth: "2",
              viewBox: "0 0 24 24"
            }, React.createElement("circle", {
                  cx: "12",
                  cy: "12",
                  r: "1"
                }), React.createElement("circle", {
                  cx: "12",
                  cy: "5",
                  r: "1"
                }), React.createElement("circle", {
                  cx: "12",
                  cy: "19",
                  r: "1"
                }));
}

var VerticalDots = {
  make: Icon$VerticalDots
};

exports.Clipboard = Clipboard;
exports.Copy = Copy;
exports.UpDownArrow = UpDownArrow;
exports.ArrowUp = ArrowUp;
exports.ArrowDown = ArrowDown;
exports.VerticalDots = VerticalDots;
/* react Not a pure module */
