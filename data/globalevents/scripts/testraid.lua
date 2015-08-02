function onTime(interval)
	-- Message broadcast
	addEvent(Game.broadcastMessage, 1000, "Rats are attacking neart Trekolt Temple!", MESSAGE_STATUS_WARNING)
	addEvent(Game.broadcastMessage, 25000, "Rats attack continues!", MESSAGE_STATUS_WARNING)

	-- Area spawns - you can use a center and radius style or using fromPos/toPos style
	local centerPos, radius = { x = 94, y = 126, z = 7 }, 5
	for i = 1, 3 do
		Raids.addSpawn(2000, "Rat", {
			x = math.random(centerPos.x - radius, centerPos.x + radius),
			y = math.random(centerPos.y - radius, centerPos.y + radius),
			z = 7,
		})
	end

	-- You can generate a random amount of creatures
	local amount = math.random(4, 10)
	for _ = 1, amount do
		local x, y = math.random(89, 99), math.random(122, 130)
		addEvent(Game.createMonster, 30000, "Rat", Position(x, y, 7))
	end

	-- Single spawns
	Raids.addSpawn(15000, "Cave Rat", { x = 93, y = 123, z = 7 })
	Raids.addSpawn(30000, "Cave Rat", { x = 98, y = 125, z = 7 })
	Raids.addSpawn(30000, "Cave Rat", { x = 94, y = 128, z = 7 })

	return true
end
