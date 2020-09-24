module Button = {
  [@react.component]
  let make = (~onClick, ~children: React.element) => {
    <button
      onClick
      className="inline-block h-8 group bg-blue active:bg-blue-dark px-4 py-2 text-white uppercase font-bold text-10 rounded-md">
      children
    </button>;
  };
};

module SendButton = {
  [@react.component]
  let make = (~onClick: ReactEvent.Mouse.t => unit) => {
    <Button onClick>
      <span className="flex items-center">
        <Icon.ArrowUp
          className="h-4 text-white-50-tr group-hover:text-white"
        />
        {React.string("send")}
      </span>
    </Button>;
  };
};

module DotButton = {
  [@react.component]
  let make = (~onClick) => {
    <button onClick className="flex justify-center w-8 text-blue-dark">
      <Icon.VerticalDots />
    </button>;
  };
};

[@react.component]
let make = (~children) => {
  let onSendClick = evt => {
    ReactEvent.Mouse.preventDefault(evt);
    Js.log("test");
  };
  let onDotClick = evt => {
    ReactEvent.Mouse.preventDefault(evt);
    Js.log("dot test ");
  };
  <div className="w-full">
    <div className="flex justify-end items-center w-full pr-4 h-12 bg-white">
      <SendButton onClick=onSendClick />
      <DotButton onClick=onDotClick />
    </div>
    <main className="flex justify-center bg-grey-10 w-full min-h-screen pt-16">
      children
    </main>
  </div>;
};
