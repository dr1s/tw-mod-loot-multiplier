# tw-mod-loot-multiplier

Rolls loot templates multiple times, giving each roll a chance to produce
different items instead of simply duplicating the first roll's results.

## How it works

The module takes over loot generation via the `OnBeforeLootGenerated` hook and
uses `Loot::ProcessLootTemplate` to roll the loot template the configured
number of times. Each pass is an independent roll, so a creature with a loot
table containing copper, linen cloth, and a green item could drop any
combination of those — not just three copies of whatever the first roll
produced.

## Configuration

Copy `conf/tw-mod-loot-multiplier.conf.dist` to `tw-mod-loot-multiplier.conf`
in the server's module config directory and adjust:

```ini
[LootMultiplier]
LootMultiplier.Enable = 1
LootMultiplier.Count  = 3
```

- `LootMultiplier.Enable` — turn the module on/off.
- `LootMultiplier.Count` — how many times to roll each loot template (1–10).

## Build

```sh
cmake -S . -B build -DMODULE_TW_MOD_LOOT_MULTIPLIER=static
```

Or use the global `-DMODULES=static` / `-DMODULES=dynamic` option.

## Requirements

Requires the core hook `LootScript::OnBeforeLootGenerated` introduced in the
accompanying core patch.
