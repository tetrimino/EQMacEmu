#include "../client.h"

void command_deletegraveyard(Client *c, const Seperator *sep){
	uint32 zoneid = 0;
	uint32 graveyard_id = 0;

	if (!sep->arg[1][0]) {
		c->Message(Chat::Default, "Usage: #deletegraveyard [zonename]");
		return;
	}

	zoneid = database.GetZoneID(sep->arg[1]);
	graveyard_id = database.GetZoneGraveyardID(zoneid);

	if (zoneid > 0 && graveyard_id > 0) {
		if (database.DeleteGraveyard(zoneid, graveyard_id))
			c->Message(Chat::Default, "Successfuly deleted graveyard %u for zone %s.", graveyard_id, sep->arg[1]);
		else
			c->Message(Chat::Default, "Unable to delete graveyard %u for zone %s.", graveyard_id, sep->arg[1]);
	}
	else {
		if (zoneid <= 0)
			c->Message(Chat::Default, "Unable to retrieve a ZoneID for the zone: %s", sep->arg[1]);
		else if (graveyard_id <= 0)
			c->Message(Chat::Default, "Unable to retrieve a valid GraveyardID for the zone: %s", sep->arg[1]);
	}

	return;
}

