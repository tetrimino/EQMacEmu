-- update Phosphorous Powder (item id 24082) loot drop entries to default min/max expansion to allow it to drop. it was previously set to min: 4 (PoP) and max : 99
UPDATE lootdrop_entries SET min_expansion = -1, max_expansion = -1 WHERE item_id = 24082
