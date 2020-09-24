[@react.component]
let make = (~route: Route.t, ~children) => {
  <a
    className="cursor-pointer"
    onClick={event => {
      ReasonReactRouter.push(Route.toHref(route));
      event->ReactEvent.Mouse.preventDefault;
    }}>
    children
  </a>;
};
