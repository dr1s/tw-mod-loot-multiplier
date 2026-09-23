#include "ScriptObjects.h"
#include "Config/Config.h"
#include "LootMgr.h"
#include "Player.h"

namespace
{
    constexpr uint32 LOOT_MULTIPLIER_MIN = 1;
    constexpr uint32 LOOT_MULTIPLIER_MAX = 10;

    class LootMultiplierScript : public LootScript
    {
    public:
        LootMultiplierScript() : LootScript("tw-mod-loot-multiplier") {}

        bool OnBeforeLootGenerated(Loot& loot, uint32 /*lootId*/, LootTemplate const& lootTemplate, LootStore const& lootStore, Player const* lootOwner, bool /*personal*/, bool /*noEmptyError*/, WorldObject const* /*looted*/) override
        {
            if (!sConfig.GetBoolDefault("LootMultiplier.Enable", false))
                return false;

            uint32 count = sConfig.GetIntDefault("LootMultiplier.Count", 1);
            if (count < LOOT_MULTIPLIER_MIN)
                count = LOOT_MULTIPLIER_MIN;
            else if (count > LOOT_MULTIPLIER_MAX)
                count = LOOT_MULTIPLIER_MAX;

            for (uint32 i = 0; i < count; ++i)
                loot.ProcessLootTemplate(lootTemplate, lootStore, lootOwner);

            return true;
        }
    };
}

void Addtw_mod_loot_multiplierScripts()
{
    new LootMultiplierScript();
}
