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

  $nf = 'custom_links_extract_bulkmode';
  $form[$nf] = array(
    '#type' => 'checkboxes',
    '#title' => 'Bulk\'s mode extracting',
    '#options' => $options,
    '#default_value' => variable_get($nf, ''),
    '#description' => 'Select the "node type" to extract all variables.',
  );
  
$optionst = array_keys($options);

  $nfg = 'custom_links_extract_singlemode';
  foreach ($optionst as $ntypes) {
    $form[$nfg . '_' . $ntypes] = array(
      '#type' => 'textarea',
      '#title' => 'list\'s mode extracting ' . $ntypes,
      '#default_value' => variable_get($nfg . '_' . $ntypes, '' ), 
      '#size' => '90',
      '#description' => 'Lists the variable\'s keys separated by commas or each rows. (ES. node_read_more, statistics_counter, taxonomy_term_TID, comment_add) All links that you extract in this section have a standard name "links_*" in example if you extract "statistics_counter" you can use in a node.tpl.php ther variable $links_statistics_counter',
      '#disabled' => FALSE
      );
  }

return system_settings_form($form);
}
