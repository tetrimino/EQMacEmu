#include "../client.h"

void command_pf(Client *c, const Seperator *sep){
	if (c->GetTarget())
	{
		Mob *who = c->GetTarget();
		c->Message(Chat::Default, "POS: (%.2f, %.2f, %.2f)", who->GetX(), who->GetY(), who->GetZ());
		c->Message(Chat::Default, "WP: %s (%d/%d)", to_string(who->GetCurrentWayPoint()).c_str(), who->IsNPC()?who->CastToNPC()->GetMaxWp():-1);
		c->Message(Chat::Default, "TAR: (%.2f, %.2f, %.2f)", who->GetTarX(), who->GetTarY(), who->GetTarZ());
		c->Message(Chat::Default, "TARV: (%.2f, %.2f, %.2f)", who->GetTarVX(), who->GetTarVY(), who->GetTarVZ());
		c->Message(Chat::Default, "|TV|=%.2f index=%d", who->GetTarVector(), who->GetTarNDX());
		c->Message(Chat::Default, "pause=%d RAspeed=%d", who->GetCWPP(), who->GetRunAnimSpeed());
	}
	else {
		c->Message(Chat::Default, "ERROR: target required");
	}
}

