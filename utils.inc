<?php

/**
 * Send the email to user
 */
function send_mail() {
  $email_content = get_mail_content();
  $params = array('body' => $email_content);
  #$subject = "text to display in e-mail subject"; // subject of e-mail
  #$body = "text to display in e-mail body"; //it might be any variable from the form eg. $form_state['values']['your_field']
  #$params = array(
  #  'subject' => $subject,
  #  'body' => $body,
  #  );
  $key = 'test_email';
  $to = 'matwilkinson@yahoo.co.uk';
  $from = 'matwilkinson@yahoo.co.uk';
  $mail = drupal_mail('test', $key, $to, language_default(), $params, $from);
  dpm($mail);
}

function test_mail($key, &$message, $params) {
  switch ($key) {
    case 'test_email':
      $message['subject'] = t('Test Email');
      $message['body'] = array($params['body']);
    break;
    }
}
function get_mail_content() {
  $email_to = 'matwilkinson@yahoo.co.uk';
  $pos = strpos($email_to, '@');
  $user_name = substr($email_to, 0, $pos);
  $body = '';
  $body .= 'Hi ' . $user_name . '<br>';
  $body .= 'Please find my test email. <br>';
  $body .= 'This is being sent cos a pub gig got added or updated' . '<br>';
  $body .= 'Thanks<br>';
  $body .= 'TestTeam';
  return $body;
}
