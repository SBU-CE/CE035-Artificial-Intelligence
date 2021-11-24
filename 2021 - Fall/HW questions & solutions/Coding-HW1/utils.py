import random
import numpy as np
import matplotlib.pyplot as plt


class City:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def distance(self, city):
        xDis = abs(self.x - city.x)
        yDis = abs(self.y - city.y)
        distance = np.sqrt((xDis ** 2) + (yDis ** 2))
        return distance
    
    def __repr__(self):
        return "(" + str(self.x) + "," + str(self.y) + ")"

def create_cities(n=25):
    city_list = []
    for i in range(n):
        city_list.append(City(x=int(random.random() * 200), y=int(random.random() * 200)))
    return city_list


def show_cities(city_list):
    for city in city_list:
        plt.scatter(city.x, city.y)

def plot_talesman_route(cities, title=None):
    for i in range(-1, len(cities)-1):
        plt.scatter(cities[i].x, cities[i].y)
        plt.quiver(cities[i].x, cities[i].y, cities[i+1].x-cities[i].x, cities[i+1].y-cities[i].y, angles='xy', scale_units='xy', scale=1)
    if plt is not None:
        plt.title(title)
    plt.show()