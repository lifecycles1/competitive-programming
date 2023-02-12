class Ticket:
  def __init__(self, requester, description):
    self.requester = requester
    self.description = description
    self.agent = None

class Agent:
  def __init__(self, name):
    self.name = name
    self.ticket_count = 0

    def assign_ticket(self, ticket):
      self.ticket_count += 1
      ticket.agent = self

class NoAgentFound(Exception):
  pass

class SupportSystem:
  def __init__(self):
    self.agents = []
    self.tickets = []

  def add_agent(self, agent):
    self.agents.append(agent)

  def add_ticket(self, ticket):
    self.tickets.append(ticket)

  def assign_tickets(self):
    self.tickets.sort(key=lambda x: x.requester)
    for ticket in self.tickets:
      agents = sorted(self.agents, key=lambda x: x.ticket_count)
      print("agentssssss", agents)
      if agents:
        agent = agents[0]
        agent.assign_ticket(ticket)
      else:
        raise NoAgentFound("No agents available to handle this ticket.")


support_system = SupportSystem()

support_system.add_agent(Agent("Alice"))
support_system.add_agent(Agent("Bob"))
support_system.add_agent(Agent("Eve"))

support_system.add_ticket(Ticket("Baba mi", "I need help with my chickens."))
support_system.add_ticket(Ticket("Your mom", "I can't log in."))
support_system.add_ticket(Ticket("Dqdka", "Hello, I need help with my account."))
support_system.add_ticket(Ticket("4i4ka", "Hello, I need to get in"))

support_system.assign_tickets()

for ticket in support_system.tickets:
  print(f"Ticket from {ticket.requester} assigned to {ticket.agent.name}")