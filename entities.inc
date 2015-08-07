<?php

/**
* Instruments callback.
*/
function show_instruments() {
  $instruments = entity_load('instrument', array(1));

  $list = entity_view('instrument', $instruments);

  $output = array();

  foreach ($list['instrument'] as $instrument) {
    $output[] = drupal_render($instrument);
  }

  dpm($output);

  return implode($output);
}

/**
 * Access callback for instrument entities.
 */
function instrument_access_callback($op, $instrument = NULL, $account = NULL) {
  if ($op == 'view' || $op == 'update' || $op == 'create' || $op == 'delete') {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * Extending the EntityAPIController for the Instrument entity.
 */
class InstrumentEntityController extends EntityAPIController {

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {

    $build = parent::buildContent($entity, $view_mode, $langcode, $content);

    // Our additions to the $build render array

    return $build;
  }
}

/**
 * Callback function for displaying the individual instrument page
 */
function show_view_instrument($id) {

  $instruments = entity_load('instrument', array($id));
  $instrument = $instruments[$id];

  drupal_set_title($instrument->name);
  $output = entity_view('instrument', array($instrument));

  return $output;
}

/**
 * Instrument entity class extending the Entity class
 */
class InstrumentEntity extends Entity {
  /**
   * Change the default URI from default/id to instrument/id
   */
  protected function defaultUri() {
    return array('path' => 'instrument/' . $this->identifier());
  }
}

/**
 * Form definition for adding / editing a instrument.
 */
function instrument_form($form, &$form_state, $instrument = NULL) {

  $form['name'] = array(
    '#title' => t('Instrument name'),
    '#type' => 'textfield',
    '#default_value' => isset($instrument->name) ? $instrument->name : '',
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => isset($instrument->id) ? t('Update instrument') : t('Save instrument'),
    '#weight' => 50,
  );

  field_attach_form('instrument', $instrument, $form, $form_state);

  return $form;
}

/**
 * Submit handler for the musician add/edit form.
 */
function instrument_form_submit($form, &$form_state) {
  $instrument = entity_ui_form_submit_build_entity($form, $form_state);
  $instrument->save();
  drupal_set_message(t('The instrument: @name has been saved.', array('@name' => $instrument->name)));
  $form_state['redirect'] = 'admin/instruments';
}
