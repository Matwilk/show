<?php

# Delete any instruments already there
$instruments = entity_load('instrument', $ids = FALSE, $conditions = array(), $reset = TRUE);
foreach ($instruments as $key => $instrument) {
  dpm($instrument);
  $instrument->delete();
}

# Create the instruments
$entity_type = 'instrument';
$entity = entity_create($entity_type, array('type' => $entity_type));
$entity->name = "Guitar";
$entity->save();
$entity = entity_create($entity_type, array('type' => $entity_type));
$entity->name = "Mandolin";
$entity->save();
$entity = entity_create($entity_type, array('type' => $entity_type));
$entity->name = "Violin";
$entity->save();
$entity = entity_create($entity_type, array('type' => $entity_type));
$entity->name = "Bass";
$entity->save();
