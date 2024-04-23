math.randomseed(os.time())
function randomNumber()
	return math.random(1,10000)
end
--moves ths ship right
function right(x, currentFrame)
	x = x+5
	if(x >= 910)then                             -- checks if x >= 910 an dif its true x is set to 910
		x=910
	end
	if (currentFrame > 1.9)then 
		currentFrame = 0
	end
	return x, currentFrame
end
-- moves the ship left
function left(x, currentFrame)
	x = x-5 
	if(x<= -5)then                              -- checks if x <= -5 an dif its true x is set to -5
		x =  -5
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

function startMessage()
    startMessages("GET READY!!!", 3)                --displays the Get ready message 
end


											    
											    
											    
function setPlayerScore()					    
	CDispatcher("setScore", 5000)		    -- adds 5000 to the score when the function is called 	    
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
