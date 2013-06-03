<?php

/**
 * @file
 * ajax callbacks
 */

/**
 * Ajax callback for flaging a node
 */
function feature_flag_flag($node, $type = 'ajax') {
  $flag = variable_set('feature_flag_' . $node->type, $node->nid);
  if ($type == 'ajax') {
    $commands = array();
    $attributes = array(
      'class' => array('use-ajax', 'flag-node-' . $node->nid, 'feature_flag_flagged'),
      'title' => t('Unflag as featured'),
    );
    $link = l(t('Unflag as featured'), 'feature_flag_unflag/' . $node->nid . '/nojs', array('attributes' => $attributes));
    $commands[] = ajax_command_replace('.flag-node-' . $node->nid, $link);
    $page = array('#type' => 'ajax', '#commands' => $commands);
    ajax_deliver($page);
  }
  else {
    $output = t("This is an ajax callback");
    return $output;
  }
}

/**
 * Ajax callback for flaging a node
 */
function feature_flag_unflag($node, $type = 'ajax') {
  if ($type == 'ajax') {
    $commands = array();
    if (variable_get('feature_flag_' . $node->type, 0) != $node->nid) {
      //if user attempts to unflag an unflagged node
      $commands[] = ajax_command_alert(t('This node is not flagged as featured'));
    }
    else {
      variable_set('feature_flag_' . $node->type, 0);
    }
    $attributes = array(
      'class' => array('use-ajax', 'flag-node-' . $node->nid, 'feature_flag_unflagged'),
      'title' => t('Flag as featured'),
    );
    $link = l(t('Flag as featured'), 'feature_flag_flag/' . $node->nid . '/nojs', array('attributes' => $attributes));
    $commands[] = ajax_command_replace('.flag-node-' . $node->nid, $link);
    $page = array('#type' => 'ajax', '#commands' => $commands);
    ajax_deliver($page);
  }
  else {
    $output = t("This is an ajax callback");
    return $output;
  }
}