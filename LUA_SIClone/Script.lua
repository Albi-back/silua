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
function left(x, currentFrame)
	x = x-5 
	if(x >= x<= -5)then 
		x = -5
	end
	if (currentFrame > 1.9)then 
		currentFrame = 0
	end
	return x, currentFrame
end

function callMessage()
	display_message("Get a Life", 1)            --displays message get a life
end											    
function callMessage2()						    
    display_message("Next Level",1 )		    --displays message next level
end 										    
											    
											    
											    
											    
function setPlayerScore()					    
	CDispatcher("setScore", 5000)			    
end											    
											    
											    
											    
											    
colour = 100                                    -- sets the colour value of the level backdrop
level = 1                                       -- sets the level number
lives = 100                                     -- sets the player lives
playerSprite = "assets/ufoph.bmp"				-- sets the string to the adress of the file of the player sprite- interchangeable as long as file keeps the same name
motherShipSprite =  "assets/Mothership.bmp"		-- sets the string to the adress of the file of the mothership sprite- interchangeable as long as file keeps the same name
playerLaser= "assets/PlayerLaser.bmp"			-- sets the string to the adress of the file of the laser projectile- interchangeable as long as file keeps the same name
ufoCounter = 0									-- sets the initial value of ufo counter
startpos  = {x=0, y=0}							-- initial postional value for the player
startpos.x = 500								-- sets x value for the start pos variable
startpos.y = 550								-- sets y value for the start pos variable 
mlives = 10                                     -- mothership lives 
mxpos = 0                                       -- mothership position on x axis
mypos = 0                                       -- mothership position on y axis