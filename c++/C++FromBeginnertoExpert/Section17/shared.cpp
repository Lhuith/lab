#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class GameResource
{ // sound/texture
public:
    GameResource(const string &n) : name(n) { cout << "loading: " << name << endl; }
    ~GameResource() { cout << "unloading: " << name << endl; }
    void useResource() const { cout << "using: " << name << endl; }

private:
    string name;
};

class GameLevel
{
    shared_ptr<GameResource> resource;

public:
    GameLevel(shared_ptr<GameResource> r) : resource(r){};
    void playLevel() const
    {
        cout << "playing level with resource" << endl;
        cout << "resource shared by: " << resource.use_count() << endl;

        resource->useResource();
    }
};

class GameManager
{
    vector<GameLevel> levels;
    shared_ptr<GameResource> commonResource;

public:
    GameManager()
    {
        // load shared resources
        commonResource = make_shared<GameResource>("CommonResource");

        // create distinct game levels that share the common resource
        /*
        each gamelevel needs access to gameresource. with unique_ptr, once transfer ownership to first gamelevel

        no other level can own or access the gameresource without complicated and error-prone manual management.

        To reduce loading times between levels, a game might preload the next level while the player is still playing the current level.

        This way, when the player completes the current level, the game can immediately transition to the next one without a disruptive loading screen.

        */

        levels.push_back(GameLevel(commonResource));
        levels.push_back(GameLevel(commonResource));
    }

    void playGame()
    {
        for (auto &level : levels) // don't forget &reference to avoid copying!
        {
            level.playLevel();
        }
    }
};

int main()
{
    GameManager gameManager;
    gameManager.playGame();

    // auto resource = make_shared<GameResource>();
    // cout << "init resource count: " << resource.use_count() << endl;

    // {
    //     shared_ptr<GameResource> resourceCopy = resource;
    //     cout << "Resource count after copy: " << resource.use_count() << endl;
    // } // resourceCopy goes out of scope here, decreasing the use count

    // cout << "final resource count: " << resource.use_count() << endl;
    return 0;
}