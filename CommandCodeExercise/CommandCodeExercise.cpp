struct Command
{
	enum Action { deposit, withdraw } action;
	int amount{ 0 };
	bool success{ false };
};

struct Account
{
	int balance{ 0 };

	void process(Command& cmd)
	{
		if (cmd.action == Command::withdraw &&
			balance >= cmd.amount)
		{
			balance -= cmd.amount;
			cmd.success = true;
		}

		if (cmd.action == Command::deposit)
		{
			balance += cmd.amount;
			cmd.success = true;
		}
	}
};