import os
import random
import sys

# Method to generate complete graphs
def generate_complete_graph(num_vertices):
    graph = [[0] * num_vertices for _ in range(num_vertices)]
    edges = 0
    for i in range(num_vertices):
        for j in range(i+1, num_vertices):
            weight = random.randint(1, 10)
            if weight > 0:
                edges += 1
            graph[i][j] = weight
            graph[j][i] = weight
    return graph, edges

# Method to generate connected graphs with a specified density coefficient
def generate_connected_graph(num_vertices, density_coefficient):
    max_edges = (num_vertices * (num_vertices - 1)) // 2
    desired_edges = int(max_edges * density_coefficient)
    
    graph = [[sys.maxsize] * num_vertices for _ in range(num_vertices)]
    edges = 0
    for i in range(num_vertices):
        graph[i][i] = 0
    
    added_edges = 0
    while added_edges < desired_edges:
        u = random.randint(0, num_vertices - 1)
        v = random.randint(0, num_vertices - 1)
        if u != v and graph[u][v] == sys.maxsize:
            weight = random.randint(1, 10)
            if weight > 0:
                edges += 1
            graph[u][v] = weight
            graph[v][u] = weight
            added_edges += 1

    return graph, edges

# Method to generate sparse graphs (trees)
def generate_sparse_graph(num_vertices):
    graph = [[0] * num_vertices for _ in range(num_vertices)]
    edges = num_vertices - 1
    for i in range(1, num_vertices):
        parent = random.randint(0, i - 1)
        weight = random.randint(1, 10)
        if weight > 0:
            edges += 1
        graph[parent][i] = weight
        graph[i][parent] = weight
    return graph, edges

# Create the output directory if it doesn't exist
output_dir = "./data/graphs"
os.makedirs(output_dir, exist_ok=True)

# Generate complete graphs with vertices ranging from 10 to 1010 (step 50)
for num_vertices in range(10, 1011, 50):
    graph, edges = generate_complete_graph(num_vertices)
    file_path = os.path.join(output_dir, f"complete_{num_vertices}.txt")
    with open(file_path, "w") as file:
        file.write(f"{num_vertices} {edges}\n")
        for row in graph:
            file.write(" ".join(map(str, row)) + "\n")

# Generate connected graphs with vertices ranging from 10 to 1010 (step 50) and density coefficient of approximately 0.4-0.5
for num_vertices in range(10, 1011, 50):
    graph, edges = generate_connected_graph(num_vertices, random.uniform(0.4, 0.5))
    file_path = os.path.join(output_dir, f"connected_{num_vertices}.txt")
    with open(file_path, "w") as file:
        file.write(f"{num_vertices} {edges}\n")
        for row in graph:
            file.write(" ".join(map(lambda x: str(x) if x != sys.maxsize else "INF", row)) + "\n")

# Generate sparse graphs (trees) with vertices ranging from 10 to 1010 (step 50)
for num_vertices in range(10, 1011, 50):
    graph, edges = generate_sparse_graph(num_vertices)
    file_path = os.path.join(output_dir, f"sparse_{num_vertices}.txt")
    with open(file_path, "w") as file:
        file.write(f"{num_vertices} {edges}\n")
        for row in graph:
            file.write(" ".join(map(str, row)) + "\n")

print("Graphs created and saved to the './data/graphs' directory.")
