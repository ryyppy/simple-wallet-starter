# Simple Wallet Starter

This is our base template for an Electron / ReScript based wallet app.

## Development

```
# Install deps
yarn

# In your vscode terminal
yarn run res:start

# In another terminal
yarn start
```

## Design Mockup

Use Figma to introspect the different UI values in our mockup:
https://www.figma.com/file/to13OFSnDid7zZOyTboyd4/Wallet-App?node-id=0%3A1

## Goal

We will isolate different components expressed in the mockup above.
Since I am a UI / UX person, I want to see some nice looking results that feel nice to the user.

The hard part about designing React applications is to figure out a design that goes well with the React rendering model (jumping UI, focus management etc.).
We will slowly divide and conquer the problems, and then wire them up with real data.

## How to approach this project?

### Thinking about the Components

Start with an `src/common/App.re` file that also adds Hot Reloading:

```reason
//src/common/App.re

type module_;
[@bs.val] external module_: module_ = "module";

// Good old hot reloader... always fun to handle that stuff!
module HotReloader = {
  type hotFn('props) =
    (. React.component('props)) => React.component('props);

  [@bs.module "react-hot-loader"]
  external hot: (. module_) => hotFn('props) = "hot";
};

// This is the core part of your App
[@react.component]
let make = () => {
  <div/>;
}

let make = (HotReloader.hot(. module_))(. make);
```

- Mount that `<App/>` component via `ReactDOM.render` in `src/Renderer.re`
- Look at the design and try to figure out component boundaries (Sidebar, Transactions page, Dashboard Page etc.)
- Try to split bigger components in smaller parts, think about the data these components will need
- In the beginning don't think about data sources at all, just use variables for mockup values
- Use the ReasonReact resources posted in the workshop notes. You can also check out the official [ReactJS Docs](https://reactjs.org) for guidance (ReasonReact apis tend to be equivalent to ReactJS' apis)

It's fine building those components in isolation. They can be composed to final components later on. Don't forget to leverage submodule components as well!

### Routing

Use the [ReasonReactRouter](https://reasonml.github.io/reason-react/docs/en/router) API and hook it up in the `src/common/App.re` component.
Since we are running on a Single Page Application, always use `hrefs` that point to anchor links (e.g. `#dashboard`, `#transactions`), otherwise you can't refresh your electron browser window with `CMD+R` without getting a `404` error (which requires you to restart your electron watcher).

Think about a `variant` type that can express the current route.

### Requesting Data

Stay away from Promises! Look at the Tips & Tricks section of the [Async & Promise Docs](https://rescript-langorg-iswe9xsbt.vercel.app/docs/manual/latest/promise#tips--tricks) for an example that uses `XMLHttpRequest` to run cancelable requests. Use the traits of those XMLHttpRequest to implement wire up cancelation in React's `useEffect`.

For the data, we will use the TezStats API to query accounts & operations on the Tezos blockchain.
- Endpoint: https://api.tzstats.com
- Wallet address 1: tz1fvLppfweTwyfrW7WuqKVicVJkWB7bJV6y 
- Wallet address 2: tz1bDXD6nNSrebqmAnnKKwnX1QdePSMCj4MX

**Querying operations**:
https://api.tzstats.com/explorer/account/{address}/operation

**Querying account**:
https://api.tzstats.com/explorer/account/{address}

You can try the queries on the browser to see the json result:
- https://api.tzstats.com/explorer/account/tz1fvLppfweTwyfrW7WuqKVicVJkWB7bJV6y/operation
- https://api.tzstats.com/explorer/account/tz1fvLppfweTwyfrW7WuqKVicVJkWB7bJV6y


### Wiring up the Data

Think about where the data request make sense. Should it happen on a route switch? If so, in which component should the request happen?

We can use the `useEffect` and `useState` hook to represent component state. Make sure to handle all different loading state edge cases:

```
type state = Init | Loading | Success(someData) | Failed(string)

[@react.component]
let make = () => {
  let (state, setState) = React.useState(_ => Init)
  // etc. etc.
<div/>
}
```
