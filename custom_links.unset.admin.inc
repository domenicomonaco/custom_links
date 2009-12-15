<?php
// $Id$

/**
 * 
 * @file
 * Modified by Domenico Monaco / info@kiuz.it / www.kiuz.it
 * Modified version of custom_links by eaton.
 * This version adding some feature to customize links of nodes, in example 
 * you can disable or extrating in bulk or single mode custom/standard links
 * with variable key es. node_read_more, statistics_counter, comment_add
 * 
 */

function custom_links_admin_settings() {

$options = node_get_types('names');

  $nf='custom_links_unset_bulkmode';
  $form[$nf] = array(
    '#type' => 'checkboxes',
    '#title' => 'Bulk\'s mode unsetting',
    '#options' => $options,
    '#default_value' => variable_get($nf, ''),
    '#description' => 'Select the "node type" to disable all variables.',
  );
  
$optionst = array_keys($options);
  
  $nfg='custom_links_unset_singlemode';
  foreach ($optionst as $ntypes) {
    $form[$nfg . '_' . $ntypes] = array(
      '#type' => 'textarea',
      '#title' => 'list\'s mode unsetting ' . $ntypes,
      '#default_value' => variable_get($nfg . '_' . $ntypes, '' ), 
      '#size' => '90',
      '#description' => 'Lists the variable\'s keys separated by commas or each rows. (ES. node_read_more, statistics_counter, taxonomy_term_TID, comment_add)',
      '#disabled' => FALSE
      );
  }

return system_settings_form($form);
}
