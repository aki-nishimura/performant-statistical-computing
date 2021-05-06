remark.macros.image = function (alignment, percentage = '100%') {
  var url = this;
  return '<img src="' + url + '" class="' + alignment + '" style="width: ' + percentage + '" />';
};

remark.macros.vspace = function (height) {
  var url = this;
  return '<p style="margin-top: ' + height + ';"> </p>';
};
