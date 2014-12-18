#ifndef LOCK_HPP
#define LOCK_HPP

class lock
{
public:
	lock();

	~lock();

	bool lock_successful() const;

private:
	bool locked;
};

#endif // !LOCK_HPP
