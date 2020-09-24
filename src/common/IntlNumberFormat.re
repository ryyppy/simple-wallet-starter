type t;

[@bs.new] [@bs.scope "Intl"]
external make: (~lang: [@bs.string] [ | [@bs.as "en-US"] `en], Js.t('a)) => t =
  "NumberFormat";

[@bs.send] external format: (t, float) => string = "format";