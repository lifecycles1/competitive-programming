class User:
    def __init__(self, name):
        self.name = name
        self.following = []

    def follow(self, other_user):
        self.following.append(other_user)

class Post:
    def __init__(self, author, content):
        self.author = author
        self.content = content

class NewsFeed:
    def __init__(self):
        self.users = {}
        self.posts = []

    def add_user(self, user):
        self.users[user.name] = user

    def add_post(self, post):
        self.posts.append(post)

    def show_feed(self, user):
        feed = []
        for post in self.posts:
            if post.author in user.following:
                feed.append(post.content)
        return feed


# Create some users
alice = User("Alice")
bob = User("Bob")
charlie = User("Charlie")

# Add them to the news feed system
news_feed = NewsFeed()
news_feed.add_user(alice)
news_feed.add_user(bob)
news_feed.add_user(charlie)

# Alice posts a message
alice_post = Post(alice, "Hello, world!")
news_feed.add_post(alice_post)

# Bob follows Alice
bob.follow(alice)

# Charlie follows Bob
charlie.follow(bob)

# Bob posts a message
bob_post = Post(bob, "Having a great day!")
news_feed.add_post(bob_post)

# Charlie can see Bob's post but not Alice's
print(news_feed.show_feed(charlie)) # ["Having a great day!"]
