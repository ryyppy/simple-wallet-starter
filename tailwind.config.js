// Check out the Design Mockup:
// https://www.figma.com/file/to13OFSnDid7zZOyTboyd4/Wallet-App?node-id=0%3A1
//
// One of the tasks is to find out what design tokens we are going to use.
//
// --COLORS--
// There are different colors defined in the UI.
// - Some are solid: #123456
// - Some are partly transparent: rgba(1,2,3,0.4)
// 
// --FONT SIZES--
// There are different font sizes, the designer forgot to add all of them
// in the design token overview, so double check in the UI if you can find
// any other text font sizes.
//
// Other than that, there's not much more to configure here later on.
// Depending on your needs, you can revisit this file and add stuff later on.
//
// Webpack / Tailwind will pick up the changes and hot-reload your app (no restart needed).
//
// Check out https://tailwindcss.com for all the CSS classes
//
module.exports = {
  future: {
    removeDeprecatedGapUtilities: true,
    purgeLayersByDefault: true,
  },
  purge: {
    content: ["./src/**/*.re"],
    options: {
      whitelist: ["html", "body"],
    },
  },
  theme: {
    extend: {
    },
    colors: {
      white: {
        default: "#FFFFFF",
      }
    },
    fontSize: {
    },
    fontWeight: {
    },
    /* We override the default font-families with our own default prefs  */
    fontFamily: {
      sans: [
        "Inter",
        "SF Pro Text",
        "Roboto",
        "-apple-system",
        "BlinkMacSystemFont",
        "Helvetica Neue",
        "Arial",
        "sans-serif",
      ],
      mono: [
        "Menlo",
        "Roboto Mono",
        "SFMono-Regular",
        "Segoe UI",
        "Courier",
        "monospace",
      ],
    },
  },
  variants: {
    textColor: ["group-hover", "hover"],
  },
  plugins: [],
};
