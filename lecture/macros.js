remark.macros.image = function (percentage = '100%', alignment = 'center') {
  var url = this;
  return '<img src="' + url + '" class="' + alignment + '" style="width: ' + percentage + '" />';
};

remark.macros.vspace = function (height) {
  var url = this;
  return '<p style="margin-top: ' + height + ';"> </p>';
};
