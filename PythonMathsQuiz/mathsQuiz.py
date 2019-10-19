# Sam Sutton - N0806708
# Maths Quiz Code

# Imports random function and Pygame
import pygame
import random
# Imports pygame functions
pygame.init()
pygame.font.init()
clock = pygame.time.Clock()
# Sets up colours
white=(255,255,255)
red=(255,0,0)
black=(0,0,0)
grey = (192,192,192)
# Sets up game display and sets caption
gameDisplay = pygame.display.set_mode((800,600))
pygame.display.set_caption('Maths Quiz')
# Maths Class - Sets the Question via the use of the random function
class Maths():
    # Function Algorithm - Assigns a random number in order to select either an Addition, Subtraction, Division
    # or a multiplication problem, before returning it for use in the button question frames
    def Algorithm():
        signMaths = random.randint(0,3)
        if signMaths == 0:
            randomInteger1,mathsSign,randomInteger2,answer = Maths.Addition()
        elif signMaths == 1:
            randomInteger1,mathsSign,randomInteger2,answer = Maths.Subtraction()
        elif signMaths == 2:
            randomInteger1,mathsSign,randomInteger2,answer = Maths.Division()
        elif signMaths == 3:
            randomInteger1,mathsSign,randomInteger2,answer = Maths.Multiply()
        return(randomInteger1,mathsSign,randomInteger2,answer)
    # Addition Function - Sets the question if a user has to solve an addition problem with random numbers
    # returns details for use in the question phase
    def Addition():
        mathsSign= ("+")
        randomInteger1=random.randint(0,10)
        randomInteger2=random.randint(0,10)
        answer = randomInteger1 + randomInteger2
        question = ("",randomInteger1," + ",randomInteger2," = ")
        return(randomInteger1,mathsSign,randomInteger2,answer)
    # Subtraction Function - Sets the question if a user has to solve an Subtraction problem with random numbers
    # where the second number is lower than the first in order to ignore negatives in the simple maths quiz
    # returns details for use in the question phase
    def Subtraction():
        mathsSign= ("-")
        randomInteger1=random.randint(0,50)
        randomInteger2=random.randint(0,randomInteger1)
        answer = randomInteger1 - randomInteger2
        question = ("",randomInteger1," - ",randomInteger2," = ")
        return(randomInteger1,mathsSign,randomInteger2,answer)
    # Division Function - Sets the question if a user has to solve an Division problem with random numbers
    # where the numbers are set to be a nice number for the user to handle
    # returns details for use in the question phase
    def Division():
        mathsSign= ("/")
        randomValueList = [2,4,5,10]
        randomInteger2=random.choice(randomValueList)
        randomInteger1=random.randrange(10,50,2)
        answer = randomInteger1 / randomInteger2
        question=("",randomInteger1," / ",randomInteger2," = ")
        return(randomInteger1,mathsSign,randomInteger2,answer)
    # Multiplication Function - Sets the question if a user has to solve an muplication problem with random numbers
    # returns details for use in the question phase
    def Multiply():
        mathsSign= ("x")
        randomInteger1=random.randint(0,10)
        randomInteger2=random.randint(0,10)
        answer = randomInteger1 * randomInteger2
        question = ("",randomInteger1," * ",randomInteger2," = ")
        return(randomInteger1,mathsSign,randomInteger2,answer)
# Class High Score - Deals with the High Score Screen and comparing scores
class highScore():
    # Function to display the top 3 scores for the table
    def highScoreScreen():
        # opens File in read mode
        openFile =open("highScoreFile.txt","r")
        # readlines of the code
        lines=openFile.readlines()
        # displays text on screen from the file
        gameDisplay.fill(white)
        largeText = pygame.font.Font("freesansbold.ttf",80)
        TextSurf, TextRect = text_objects("High Score Table", largeText)
        TextRect.center = ((400),(100))
        gameDisplay.blit(TextSurf, TextRect)
        largeText = pygame.font.Font("freesansbold.ttf",40)
        TextSurf, TextRect = text_objects("1 - "+lines[1]+"   "+lines[0], largeText)
        TextRect.center = ((400),(200))
        gameDisplay.blit(TextSurf, TextRect)
        largeText = pygame.font.Font("freesansbold.ttf",40)
        TextSurf, TextRect = text_objects("2 - "+lines[3]+"   "+lines[2], largeText)
        TextRect.center = ((400),(300))
        gameDisplay.blit(TextSurf, TextRect)
        largeText = pygame.font.Font("freesansbold.ttf",40)
        TextSurf, TextRect = text_objects("3 - "+lines[5]+"   "+lines[4], largeText)
        TextRect.center = ((400),(400))
        gameDisplay.blit(TextSurf, TextRect)
        # closes the file
        openFile.close()
        # creates buttons for user navigation
        button(str("Start Screen"),40,500,210,50,grey)
        button(str("Quit"),550,500,200,50,grey)
        # updates the display
        pygame.display.update()
        clock.tick(15)
        # if user clicks in the specific area of the button
        # then take them to a different function
        answered2 = False
        while answered2 == False:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    quitGame() 
                if event.type == pygame.MOUSEBUTTONDOWN:
                    mouse = pygame.mouse.get_pos()
                    if 40 < mouse[0] < 250 and 500 < mouse[1] < 550:
                        answered2 = True
                        main()             
                    elif 550 < mouse[0] < 750 and 500 < mouse[1] < 550:
                        answered2 = True
                        quitGame()
    # Function which compares scores in current high score file to the new score generated by the user
    def highScoreUpdate(text,score):
        # file handling
        # opens file
        openFile =open("highScoreFile.txt","r")
        # read lines and assigns it to variables
        lines=openFile.readlines()
        topScore = lines[0]
        topName = lines[1]
        secondScore = lines[2]
        secondName = lines[3]
        thirdScore = lines[4]
        # closes file
        openFile.close()
        # compares file values to new score and overwrites the file     
        if score > int(thirdScore):
            openFile = open("highScoreFile.txt","w")
            if score > int(secondScore):
                if score > int(topScore):
                    openFile.write(str(score)+"\n")
                    openFile.write((text)+"\n")
                    openFile.write(str(topScore))
                    openFile.write((topName))
                    openFile.write(str(secondScore))
                    openFile.write(secondName)
                else:
                    openFile.write(str(topScore))
                    openFile.write((topName))
                    openFile.write(str(score)+"\n")
                    openFile.write((text)+"\n")
                    openFile.write(str(secondScore))
                    openFile.write(secondName)
            else:
                openFile.write(str(topScore))
                openFile.write((topName))
                openFile.write(str(secondScore))
                openFile.write((secondName))
                openFile.write(str(score)+"\n")
                openFile.write(text)
        else:
            print("Not in the top three")
        # closes the file
        openFile.close()
        # calls the screen to show the top 3 table
        highScore.highScoreScreen()



    ## Code Adapted from https://stackoverflow.com/questions/46390231/how-to-create-a-text-input-box-with-pygame by user: skrx
    def userInput():
        # sets the font size
        font = pygame.font.Font(None, 32)
        # creates the input box variable
        input_box = pygame.Rect(100, 100, 140, 32)
        # sets variable needed for the input box
        active = False
        # stores text entered into the box
        text = ''
        done = False
        # whilst user is still typing
        while not done:
            # for events in the user
            for event in pygame.event.get():
                # if quit then do this
                if event.type == pygame.QUIT:
                    done = True
                    quitGame()
                if event.type == pygame.MOUSEBUTTONDOWN:
                    # If the user clicked on the input_box rect.
                    if input_box.collidepoint(event.pos):
                        # Toggle the active variable.
                        active = not active
                    else:
                        active = False
                    # Change the current color of the input box.
                if event.type == pygame.KEYDOWN:
                    if active:
                        # if user enters return then the user is done typing and the game moves on
                        if event.key == pygame.K_RETURN:
                            active = False
                            done = True
                            gameDisplay.fill(white)
                            return(text)
                        # backspace will remove the last letter 
                        elif event.key == pygame.K_BACKSPACE:
                            text = text[:-1]
                        else:
                            text += event.unicode
            # fills the display with text and on to a white background
            # Adds in the text box where the user will have to click in order to make it active
            gameDisplay.fill(white)
            # Render the current text.
            txt_surface = font.render(text, True, red)
            Text1 = pygame.font.Font("freesansbold.ttf",25)
            TextSurf, TextRect = text_objects("Enter your name >", Text1)
            TextRect.center = ((200),(25))
            gameDisplay.blit(TextSurf, TextRect)
            TextSurf, TextRect = text_objects("Click RETURN when finished entering name", Text1)
            TextRect.center = ((350),(75))
            gameDisplay.blit(TextSurf, TextRect)
            # Resize the box if the text is too long.
            width = max(200, txt_surface.get_width()+10)
            input_box.w = width
            # Blit the text.
            gameDisplay.blit(txt_surface, (input_box.x+5, input_box.y+5))
            # Blit the input_box rect.
            pygame.draw.rect(gameDisplay, red, input_box, 2)
            # updates game display
            pygame.display.update()
            clock.tick(30)
    # Function for highScoreRunner - knits together the high score class and allows text and score to be obtained        
    def highScoreRunner(score):
        text = highScore.userInput()
        print(text)
        highScore.highScoreUpdate(text,score)
        
## Code adapted from youtube user Semtdex via his Tutorial
# Took solely from semtdex to centre text on the button
def text_objects(text, font):
    # renders the text for the user
    textSurface = font.render(text, True, red)
    return textSurface, textSurface.get_rect()
# Button code adapted from Semtdex
def button(msg,x,y,w,h,ic):
    # creates rectangles
    pygame.draw.rect(gameDisplay, ic,(x,y,w,h))
    # centres the text in the button
    smallText = pygame.font.SysFont("freesansbold.ttf",50)
    textSurf, textRect = text_objects(msg, smallText)
    textRect.center = ( (x+(w/2)), (y+(h/2)) )
    gameDisplay.blit(textSurf, textRect)
# Function Question 
def question():
    # Calls Maths Algorithm for a question
    randomInteger1,mathsSign, randomInteger2,answer = Maths.Algorithm()
    # appends answer to answer list which stores answers to be added onto the multiple choice buttons
    answers=[]
    answers.append(answer)
    wrongNumbers = 0
    # While answers are lower than 4
    while len(answers) < 4:

        # generates numbers
        randomNumber= random.randint((1),(20))
        # makes sure that the generated wrong answer is not the same as the correct answer
        if randomNumber == answer:
            pass
        else:
            # appends answers to list
            answers.append(randomNumber)
    # shuffles the list so that the right answer is in a different position
    random.shuffle(answers)
    # creates the question varaible
    mathsQuestion =(""+str(randomInteger1)+" "+str(mathsSign)+" "+str(randomInteger2)+" = ")
    # returns the question variable as well as the list of all answers and the correct answer
    return(mathsQuestion,answers,answer)
# Function which creates the frame for the questions and answers
def questionFrame():
    # sets the starting score at 0
    score = 0
    # whilst the user has not got a question wrong or not quit by choice
    gameExit = False
    while not gameExit:
        # calls the question function for the information to be displayed on the display 
        mathsQuestion,answers,answer=question()
        # sets the question, boxes and exit button and display it to the game display
        gameDisplay.fill(white)
        font = pygame.font.Font("freesansbold.ttf", 48)
        text = font.render(mathsQuestion, True, black)
        gameDisplay.blit(text, (275, 100))
        font = pygame.font.Font("freesansbold.ttf", 25)
        text = font.render("Score "+str(score), True, black)
        gameDisplay.blit(text, (25, 25))
        button(str(answers[0]),237.5,250,150,150,grey)
        button(str(answers[1]),412.5,250,150,150,grey)
        button(str(answers[2]),237.5,425,150,150,grey)
        button(str(answers[3]),412.5,425,150,150,grey)
        button(str("X"),750,10,40,40,grey)
        pygame.display.update()
        clock.tick(15)
        # whilst the user has not chose a box or the exit button
        # makes sure that the user has to click an option before continuing
        answered = False
        while answered == False:
            # loops round in pygame events
            for event in pygame.event.get():
                # if user clicks the close window then exits the maths quiz
                if event.type == pygame.QUIT:
                    quitGame()
                # if the user choses the option then go to check if the answer is correct
                # and stop the answer loop so if the user gets the question right then the score is implemeneted by 1 and
                # a new question is generated
                if event.type == pygame.MOUSEBUTTONDOWN:
                    mouse = pygame.mouse.get_pos()
                    if 237.5 < mouse[0] < 387.5 and 250 < mouse[1] < 400:
                        correct,score = answerCorrect(answer,score,option = answers[0])
                        if correct == False:
                            gameExit = True
                            gameOverScreen(score)
                        else:
                            answered = True
                    elif 412.5 < mouse[0] < 562.5 and 250 < mouse[1] < 400:
                        correct,score = answerCorrect(answer,score,option = answers[1])
                        if correct == False:
                            gameExit = True
                            gameOverScreen(score)                                         
                        else:
                            answered = True                         
                    elif 237.5 < mouse[0] < 387.5 and 425 < mouse[1] < 575:
                        correct,score = answerCorrect(answer,score,option = answers[2])
                        if correct == False:
                            gameExit = True
                            gameOverScreen(score)                                         
                        else:
                            answered = True
                    elif 412.5 < mouse[0] < 562.5 and 425 < mouse[1] < 575:
                        correct,score = answerCorrect(answer,score,option = answers[3])
                        if correct == False:
                            gameExit = True
                            gameOverScreen(score)                                         
                        else:
                            answered = True
                    # if the user clicks the exit button then quit the game
                    elif 640 < mouse[0] < 790 and 10 < mouse[1] < 60:
                        quitGame()
                        answered = True
# Function for the user to show when the user gets a question wrong
def gameOverScreen(score):
    # sets the sipaly to a white background and presents a game over message and the score is also displayed
    # creates buttons for the user to clixk
    gameDisplay.fill(white)
    largeText = pygame.font.Font("freesansbold.ttf",70)
    TextSurf, TextRect = text_objects("GAME OVER", largeText)
    TextRect.center = ((400),(100))
    gameDisplay.blit(TextSurf, TextRect)
    TextSurf, TextRect = text_objects("SCORE: "+str(score), largeText)
    TextRect.center = ((400),(300))
    gameDisplay.blit(TextSurf, TextRect)
    button(str("Start Screen"),40,500,210,50,grey)
    button(str("Continue"),300,500,210,50,grey)
    button(str("Quit"),550,500,200,50,grey)
    pygame.display.update()
    clock.tick(15)
    # loops round the events of the user and will not move from the screen until the user gives an input which correlates to an option beloww
    # in this case it is a click in areas around the button
    answered2 = False
    while answered2 == False:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                quitGame() 
            if event.type == pygame.MOUSEBUTTONDOWN:
                mouse = pygame.mouse.get_pos()
                if 40 < mouse[0] < 250 and 500 < mouse[1] < 550:
                    answered2 = True
                    main()         
                elif 300 < mouse[0] < 510 and 500 < mouse[1] < 550:
                    answered2 = True
                    highScore.highScoreRunner(score)       
                elif 550 < mouse[0] < 750 and 500 < mouse[1] < 550:
                    answered2 = True
                    quitGame()
# Function answerCorrect - shows if the answer and the option is the same then implements the score and continues
# if not then correct is returned False and then the questions are no longer being generated and the game over screen
# is displayed
def answerCorrect(answer,score,option):
    if option == answer:
        correct = True
        score = score + 1
    else:
        correct = False
    return(correct,score)
# Function to quit the Game
def quitGame():
    pygame.quit()
    quit()
# main runner for the pygame program
def main():
    # whilst the introduction is occuring
    intro = True
    while intro:
        # loops round the events of the user and will not move from the screen until the user gives an input which correlates to an option beloww
        # in this case it is a click in areas around the button
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                gameExit = True
                pygame.quit()
                quit()
            if event.type == pygame.MOUSEBUTTONDOWN:
                mouse = pygame.mouse.get_pos()
                if 95 < mouse[0] < 705 and 205 < mouse[1] < 285:
                    questionFrame()
                elif 95 < mouse[0] < 705 and 325 < mouse[1] < 405:
                    highScore.highScoreScreen()
                elif 95 < mouse[0] < 705 and 445 < mouse[1] < 515:
                    quitGame()
        # displays user buttons and text onto a white background
        gameDisplay.fill(white)
        largeText = pygame.font.Font("freesansbold.ttf",115)
        TextSurf, TextRect = text_objects("Maths Quiz", largeText)
        TextRect.center = ((400),(100))
        gameDisplay.blit(TextSurf, TextRect)
        button("",95,205,610,80,black)
        button("PLAY",100,210,600,70,white)
        button("",95,325,610,80,black)
        button("HIGH SCORES",100,330,600,70,white)
        button("",95,445,610,80,black)
        button("QUIT",100,450,600,70,white)        
        pygame.display.update()
        clock.tick(15)
# calls the main runner of the program        
main()
