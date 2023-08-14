import pygame
import sys
import random
from math import *
import mediapipe as mp
import cv2

pygame.init()

width = 500
height = 500

display = pygame.display.set_mode((width, height))
pygame.display.set_caption("Finger Counting Game")
clock = pygame.time.Clock()

white = (255, 255, 255)
black = (0, 0, 0)

font = pygame.font.SysFont("Arial", 50)

mp_hands = mp.solutions.hands
cap = cv2.VideoCapture(0)


def findFingerCount():
    ret, frame = cap.read()

    # BGR 2 RGB
    image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    # Flip on horizontal
    image = cv2.flip(image, 1)

    # Set flag
    image.flags.writeable = False

    # Detections
    results = hands.process(image)

    # Set flag to true
    image.flags.writeable = True

    # Detections

    # Counting fingers
    finger_count = 0
    if results.multi_hand_landmarks:
        landmark_list = results.multi_hand_landmarks[0].landmark
        tip_ids = [4, 8, 12, 16, 20]  # Index finger, Middle finger, Ring finger, Little finger, Thumb
        for tip_id in tip_ids:
            tip = landmark_list[tip_id]
            if tip.y < landmark_list[tip_id - 2].y:  # Checking if finger is raised
                finger_count += 1

    return finger_count


def showTargetNumber(number):
    targetText = font.render(str(number), True, black)
    display.blit(targetText, (width // 2 - 25, height // 2 - 25))


def showResultMessage(result):
    if result:
        resultText = font.render("Correct!", True, (0, 128, 0))
    else:
        resultText = font.render("Try Again!", True, (255, 0, 0))
    display.blit(resultText, (width // 2 - 90, height // 2 + 50))


def showScore(score):
    scoreText = font.render("Score: " + str(score), True, black)
    display.blit(scoreText, (20, 20))


def close():
    pygame.quit()
    sys.exit()


def game():
    loop = True
    score = 0
    while loop:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                close()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    close()
                if event.key == pygame.K_r:
                    game()

        display.fill(white)

        finger_count = findFingerCount()

        target_number = random.randint(0, 5)
        showTargetNumber(target_number)

        result = finger_count == target_number

        if result:
            score += 1

        showResultMessage(result)
        showScore(score)

        pygame.display.update()
        clock.tick(60)


with mp_hands.Hands(min_detection_confidence=0.8, min_tracking_confidence=0.5) as hands:
    game()
