[@react.component]
let make = (~href: string, ~children) => {
  <a
    className="cursor-pointer"
    onClick={event => {
      Js.log(href);
      event->ReactEvent.Mouse.preventDefault;
    }}>
    children
  </a>;
};
