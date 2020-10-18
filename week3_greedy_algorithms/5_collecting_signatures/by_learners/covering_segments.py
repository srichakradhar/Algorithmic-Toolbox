# Uses python3
import sys
from collections import namedtuple

Segment = namedtuple('Segment', 'start end')

def optimal_points(segments):
    
    weights = {}
    segments = sorted(segments, key=lambda x: x.start)
    start = segments[0][0]
    end = segments[-1][1]
    points = list(range(start, end + 1))
    for s in segments:
        for i in points:
            if i in weights:
                weights[i] += 1
            else:
                weights[i] = 0
    points = sorted(points, key=lambda x: weights[x], reverse=True)
    # Remove points in common with max weight
    unvisited_segments = segments
    answer = []
    while(len(unvisited_segments) > 0):
        point = points[0]
        answer.append(point)
        print(point)
        print(unvisited_segments)
        for s in unvisited_segments:
            print(s)
            if point in range(s.start, s.end + 1):
                unvisited_segments.remove(s)
                points.remove(point)
        
    return answer

if __name__ == '__main__':
    inp = input()
    n = int(inp)
    segments = []
    for i in range(n):
        segments.append(list(map(int, input().split())))
    segments = list(map(lambda x: Segment(x[0], x[1]), segments))
    # segments = list(map(lambda x: Segment(x[0], x[1]), zip(data[::2], data[1::2])))
    points = optimal_points(segments)
    print(len(points))
    print(*points)
