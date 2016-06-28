function onSay(player, words, param)
	if not player:getGroup():getAccess() then
		return true
	end

	if player:getAccountType() < ACCOUNT_TYPE_GAMEMASTER then
		return false
	end

	-- prevent forcing server save through /raid
	if param == "Server Save" or not Game.startEvent(param) then
		player:sendCancelMessage("There is no raid with that name.")
	end
	return true
end
