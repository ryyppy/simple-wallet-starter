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

module Clicker = {
  type data =
    | Init
    | Loading
    | Success(string)
    | Failed(string);

  [@react.component]
  let make = () => {
    let (count, setCount) = React.useState(_ => 0);

    let (data, setData) = React.useState(_ => Init);

    React.useEffect1(
      () => {
        setData(_ => Loading);
        let watchId =
          Js.Global.setTimeout(
            () => {
              setData(_ =>
                Success("Found 123 (" ++ Belt.Int.toString(count) ++ ")")
              )
            },
            Js.Math.abs_int(1000 * count),
          );

        let cleanup = () => {
          Js.Global.clearTimeout(watchId);
        };

        Some(cleanup);
      },
      [|count|],
    );

    let increase = evt => {
      ReactEvent.Mouse.preventDefault(evt);
      setCount(prev => prev + 1);
    };
    let decrease = evt => {
      ReactEvent.Mouse.preventDefault(evt);
      setCount(prev => prev - 1);
    };

    let dataElement =
      switch (data) {
      | Init
      | Loading => React.string("Loading...")
      | Success(data) => React.string(data)
      | Failed(msg) => React.string("Failed with " ++ msg)
      };

    let buttonClass = "text-16 w-4 h-4 rounded bg-grey-10";
    <div className="flex items-center justify-center bg-blue w-1/3 h-20">
      <div> <h2> dataElement </h2> </div>
      <div>
        <button onClick=decrease className=buttonClass>
          {React.string("-")}
        </button>
        <span className="w-8 font-bold text-36"> {React.int(count)} </span>
        <button onClick=increase className=buttonClass>
          {React.string("+")}
        </button>
        <button onClick={_evt => setCount(_ => 0)}>
          {React.string("Reset")}
        </button>
      </div>
    </div>;
  };
};

[@react.component]
let make = () => {
  let onSendClick = evt => {
    ReactEvent.Mouse.preventDefault(evt);
    Js.log("test");
  };
  let onDotClick = evt => {
    ReactEvent.Mouse.preventDefault(evt);
    Js.log("dot test ");
  };

  <div>
    <div className="flex justify-end items-center w-full pr-4 h-12 bg-white">
      <SendButton onClick=onSendClick />
      <DotButton onClick=onDotClick />
    </div>
    <main className="flex justify-center bg-grey-10 w-full min-h-screen pt-16">
      <div className="w-full" style={ReactDOMStyle.make(~maxWidth="34rem", ())}>
        <AccountOverview
          avatar="/static/img/default-avatar.png"
          name="Bruno"
          address="tz1LbSsDSmekew3prdDGx1nS22ie6jjBN6B3"
          balance=42.
        />
      </div>
    </main>
  </div>;
};
