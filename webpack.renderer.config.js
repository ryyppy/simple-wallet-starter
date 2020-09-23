const path = require("path");
const rules = require("./webpack.rules");
const CopyWebpackPlugin = require("copy-webpack-plugin");

const assets = ["img", "fonts"];

rules.push({
  test: /\.css$/,
  use: [
    { loader: "style-loader" },
    { loader: "css-loader" },
    { loader: "postcss-loader" },
  ],
});

module.exports = {
  // Put your normal webpack config below here
  module: {
    rules,
  },
  resolve: {
    alias: { "react-dom": "@hot-loader/react-dom" },
  },
  plugins: assets.map((dir) => {
    return new CopyWebpackPlugin({
      patterns: [
        {
          from: path.resolve(__dirname, "src", "assets", dir),
          to: path.resolve(__dirname, ".webpack/renderer", "static", dir),
        },
      ],
    });
  }),
};
