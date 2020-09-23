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
      transitionProperty: {
        left: "left",
      },
      maxWidth: {
        "700": "43.75rem",
      },
      borderRadius: {
        md: "0.5rem",
        lg: "1rem",
      },
    },
    // We only allow these colors
    //
    // Explanation:
    // -------------
    // blue-90 => blue on 90% opacitiy, but solid
    // white-50-tr => white on 50% opacity, translucent
    colors: {
      // Primary color
      blue: {
        default: "#2C7DF7",
        dark: "#201E86",
        "90": "#123262",
      },
      // White / Greyscale
      grey: {
        "10": "#EFF0F2",
        "40": "#A8B2C1",
      },
      white: {
        default: "#FFFFFF",
        "10-tr": "rgba(255, 255, 255, 0.1)",
        "20-tr": "rgba(255, 255, 255, 0.2)",
        "50-tr": "rgba(255, 255, 255, 0.5)",
        "90-tr": "rgba(255, 255, 255, 0.9)",
      },
      // Additional colors
      green: {
        light: "#E6F7EB",
        default: "#06AF35",
      },
      red: {
        default: "#ED4664",
        "10-tr": "rgba(237, 70, 100, 0.1)",
      },
    },
    fontSize: {
      "10": "0.625rem",
      "14": "0.875rem",
      "16": "1rem",
      "36": "2.25rem",
    },
    fontWeight: {
      normal: 400,
      medium: 500,
      semibold: 600,
      bold: 700,
      extrabold: 800,
      black: 900,
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
    backgroundColor: ['hover', 'focus', 'active'],
  },
  plugins: [],
};
