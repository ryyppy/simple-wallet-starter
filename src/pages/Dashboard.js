// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Icon = require("../common/Icon.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");

function Dashboard$Button(Props) {
  var onClick = Props.onClick;
  var children = Props.children;
  return React.createElement("button", {
              className: "inline-block h-8 group bg-blue active:bg-blue-dark px-4 py-2 text-white uppercase font-bold text-10 rounded-md",
              onClick: onClick
            }, children);
}

var Button = {
  make: Dashboard$Button
};

function Dashboard$SendButton(Props) {
  var onClick = Props.onClick;
  return React.createElement(Dashboard$Button, {
              onClick: onClick,
              children: React.createElement("span", {
                    className: "flex items-center"
                  }, React.createElement(Icon.ArrowUp.make, {
                        className: "h-4 text-white-50-tr group-hover:text-white"
                      }), "send")
            });
}

var SendButton = {
  make: Dashboard$SendButton
};

function Dashboard$DotButton(Props) {
  var onClick = Props.onClick;
  return React.createElement("button", {
              className: "flex justify-center w-8 text-blue-dark",
              onClick: onClick
            }, React.createElement(Icon.VerticalDots.make, {}));
}

var DotButton = {
  make: Dashboard$DotButton
};

function Dashboard$Clicker(Props) {
  var match = React.useState(function () {
        return 0;
      });
  var setCount = match[1];
  var count = match[0];
  var match$1 = React.useState(function () {
        return /* Init */0;
      });
  var setData = match$1[1];
  var data = match$1[0];
  React.useEffect((function () {
          Curry._1(setData, (function (param) {
                  return /* Loading */1;
                }));
          var watchId = setTimeout((function (param) {
                  return Curry._1(setData, (function (param) {
                                return {
                                        TAG: /* Success */0,
                                        _0: "Found 123 (" + (String(count) + ")")
                                      };
                              }));
                }), Math.abs(Math.imul(1000, count)));
          return (function (param) {
                    clearTimeout(watchId);
                    
                  });
        }), [count]);
  var increase = function (evt) {
    evt.preventDefault();
    return Curry._1(setCount, (function (prev) {
                  return prev + 1 | 0;
                }));
  };
  var decrease = function (evt) {
    evt.preventDefault();
    return Curry._1(setCount, (function (prev) {
                  return prev - 1 | 0;
                }));
  };
  var dataElement;
  dataElement = typeof data === "number" ? "Loading..." : (
      data.TAG ? "Failed with " + data._0 : data._0
    );
  var buttonClass = "text-16 w-4 h-4 rounded bg-grey-10";
  return React.createElement("div", {
              className: "flex items-center justify-center bg-blue w-1/3 h-20"
            }, React.createElement("div", undefined, React.createElement("h2", undefined, dataElement)), React.createElement("div", undefined, React.createElement("button", {
                      className: buttonClass,
                      onClick: decrease
                    }, "-"), React.createElement("span", {
                      className: "w-8 font-bold text-36"
                    }, count), React.createElement("button", {
                      className: buttonClass,
                      onClick: increase
                    }, "+"), React.createElement("button", {
                      onClick: (function (_evt) {
                          return Curry._1(setCount, (function (param) {
                                        return 0;
                                      }));
                        })
                    }, "Reset")));
}

var Clicker = {
  make: Dashboard$Clicker
};

function Dashboard(Props) {
  var onSendClick = function (evt) {
    evt.preventDefault();
    console.log("test");
    
  };
  var onDotClick = function (evt) {
    evt.preventDefault();
    console.log("dot test ");
    
  };
  return React.createElement("div", undefined, React.createElement("div", {
                  className: "flex justify-end items-center w-full pr-4 h-12 bg-white"
                }, React.createElement(Dashboard$SendButton, {
                      onClick: onSendClick
                    }), React.createElement(Dashboard$DotButton, {
                      onClick: onDotClick
                    })), React.createElement("main", {
                  className: "bg-grey-10 w-full min-h-screen"
                }, React.createElement(Dashboard$Clicker, {})));
}

var make = Dashboard;

exports.Button = Button;
exports.SendButton = SendButton;
exports.DotButton = DotButton;
exports.Clicker = Clicker;
exports.make = make;
/* Icon Not a pure module */