// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Icon = require("../common/Icon.js");
var React = require("react");

function MainLayout$Button(Props) {
  var onClick = Props.onClick;
  var children = Props.children;
  return React.createElement("button", {
              className: "inline-block h-8 group bg-blue active:bg-blue-dark px-4 py-2 text-white uppercase font-bold text-10 rounded-md",
              onClick: onClick
            }, children);
}

var Button = {
  make: MainLayout$Button
};

function MainLayout$SendButton(Props) {
  var onClick = Props.onClick;
  return React.createElement(MainLayout$Button, {
              onClick: onClick,
              children: React.createElement("span", {
                    className: "flex items-center"
                  }, React.createElement(Icon.ArrowUp.make, {
                        className: "h-4 text-white-50-tr group-hover:text-white"
                      }), "send")
            });
}

var SendButton = {
  make: MainLayout$SendButton
};

function MainLayout$DotButton(Props) {
  var onClick = Props.onClick;
  return React.createElement("button", {
              className: "flex justify-center w-8 text-blue-dark",
              onClick: onClick
            }, React.createElement(Icon.VerticalDots.make, {}));
}

var DotButton = {
  make: MainLayout$DotButton
};

function MainLayout(Props) {
  var children = Props.children;
  var onSendClick = function (evt) {
    evt.preventDefault();
    console.log("test");
    
  };
  var onDotClick = function (evt) {
    evt.preventDefault();
    console.log("dot test ");
    
  };
  return React.createElement("div", {
              className: "w-full"
            }, React.createElement("div", {
                  className: "flex justify-end items-center w-full pr-4 h-12 bg-white"
                }, React.createElement(MainLayout$SendButton, {
                      onClick: onSendClick
                    }), React.createElement(MainLayout$DotButton, {
                      onClick: onDotClick
                    })), React.createElement("main", {
                  className: "flex justify-center bg-grey-10 w-full min-h-screen pt-16"
                }, children));
}

var make = MainLayout;

exports.Button = Button;
exports.SendButton = SendButton;
exports.DotButton = DotButton;
exports.make = make;
/* Icon Not a pure module */
