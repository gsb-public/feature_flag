<?php

/*
 * Admin functions for feature flag module
 */

function feature_flag_config() {
  $types = node_type_get_types();
  $form = array();
  $form['label'] = array('#markup' => t('Apply featured flag for the following content types:'));
  
  foreach ($types as $type => $object) {
    $form['feature_flag_' . $type . '_activated'] = array(
      '#type' => 'checkbox',
      '#default_value' => variable_get('feature_flag_' . $type . '_activated', 0),
      '#title' => $object->name,
    );
  }
  return system_settings_form($form);
}