math.randomseed(os.time())
function randomNumber()
	return math.random(1,10000)
end
function right(x, currentFrame)
	x = x+5
	if(x >= 910)then 
		x=910
	end
	if (currentFrame > 1.9)then 
		currentFrame = 0
	end
	return x, currentFrame
end

function callMessage()
	display_message("Get a Life", 1)
end
function callMessage2()
    display_message("Next Level",1 )
end 




function setPlayerScore()
	CDispatcher("setScore", 5000)
end




colour = 100
level = 1
lives = 100
playerSprite = "assets/ufoph.bmp"
motherShipSprite =  "assets/Mothership.bmp"
startpos  = {x=0, y=0}
startpos.x = 500
startpos.y = 550