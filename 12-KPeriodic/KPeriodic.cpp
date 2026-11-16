#include "KPeriodic.h"

bool IsKPeriodic(const std::string& text, int k)
{
    if (k <= 0 || text.empty())
    {
        return false;
    }

    const auto period = static_cast<std::string::size_type>(k);
    const auto length = text.size();
    if (length % period != 0)
    {
        return false;
    }

    // Каждый следующий блок должен совпадать с предыдущим.
    for (auto i = period; i < length; ++i)
    {
        if (text[i] != text[i - period])
        {
            return false;
        }
    }
    return true;
}
