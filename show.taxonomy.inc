<?php
/**
 * @file
 * shows.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function show_taxonomy_default_vocabularies() {
  return array(
    'type' => array(
      'name' => 'Show Type',
      'machine_name' => 'type',
      'description' => 'Type of show - e.g. Pub, Wedding, Festival',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
