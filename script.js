// togg
(function ($) {
  Drupal.behaviors.togg = {
    attach: function (context, settings) {
      $('a#togg-link:not(.togg-processed)', context).addClass('togg-processed').each(function () {
        $(this).click(function() {
          $("div#togg").toggle(400);
          return false;
        });
      });
    }
  };
}(jQuery));
