%raw
"import './css/main.css'";

// This is the entry point for our webclient

// Use the ReactDOM.render api to render your app.
// See: https://rescript-langorg-iswe9xsbt.vercel.app/docs/react/latest/rendering-elements#rendering-elements-to-the-dom


switch (ReactDOM.querySelector("#root")) {
| Some(root) => ReactDOM.render(<App />, root)
| None => () // do nothing
};

