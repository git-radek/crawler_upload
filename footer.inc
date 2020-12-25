<?php
function show_footer($time_start) {
global $key;
$time_end = microtime(true);
$time = round($time_end - $time_start,2);
echo "<div id='footer'>Request has been completed in: $time.s</div>";
?>
<script>
function makeid(length) {
   var result           = '';
   var characters       = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
   var charactersLength = characters.length;
   for ( var i = 0; i < length; i++ ) {
      result += characters.charAt(Math.floor(Math.random() * charactersLength));
   }
   return result;
}

jQuery(document).ready(function($) {
    $('*[data-href]').on('click', function() {
        $('#container').first().fadeIn( "slow" );
        $('#container').load($(this).data('href'));
        //window.location = $(this).data('href');
    });

    $('#container').on('click', function() {
        $('#container').hide();
        //window.location = $(this).data('href');
    });
});

$("#fileupload").fileupload({
  dataType: "json",
//  formData: { key: makeid(40), desc: $('#desc').val() }, 
  add: function(e, data) {
    data.context = $('<p class="file">')
      .append($('<a target="_blank">').text(data.files[0].name))
      .appendTo(document.body);
    data.submit();
  },
  progress: function(e, data) {
    var progress = parseInt((data.loaded / data.total) * 100, 10);
    data.context.css("background-position-x", 100 - progress + "%");
  },
  done: function(e, data) {
    data.context
      .addClass("done")
      .find("a")
      .prop("href", data.result.files[0].url);
      var r = data.result;
      //$('#container').append($(this).data(r));
      //$('#container').append($(r).text(html));
      //$('#container').show();
  }
})
.on('fileuploadsubmit', function (e, data) {
data.formData = { key: makeid(40), desc: $('#desc').val() }; });


function toggleAB(){ var el = this; 
return [ 
function() { $('.debug').css('display', 'none'); }, 
function() { $('.debug').css('display', 'block'); }
][el.tog^=1](); }

$("#debug_switch").click( toggleAB );

//$('#debug_switch').toggle(function() { $('.debug').css('display', 'block'); }, function() { $('.debug').css('display', 'none'); });
// $( "#debug_switch" ).toggle(function() { alert( "First handler for .toggle() called." );}, function() { alert( "Second handler for .toggle() called." );});
</script>


</div></body></html>
<?php } ?>
