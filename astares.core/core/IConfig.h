#ifndef CONFIG_H
#define CONFIG_H

#include "../astares.core.h"
#include "../core/Types.h"
#include <map>

/**
(Name0)
[
Variable0 = Value0
Variable1 = Value1
]
**/

namespace astares
{
	struct ASTARESCORE_API IConfig {
		virtual ~IConfig();

		virtual IConfig& MoveSection(cstring section) = 0;

		virtual bool HasSetting(cstring setting) const = 0;
		virtual bool HasSection(cstring section) const = 0;

		virtual bool AsBool(cstring setting) const = 0;
		virtual cstring AsString(cstring setting) const = 0;
		virtual f32 AsFloat(cstring setting) const = 0;
		virtual int32 AsInt(cstring setting) const = 0;

		virtual void Parse(cstring content) = 0;

		void operator=(const IConfig& rhs);

		static inline IConfig* MakeConfig(cstring filename);

	protected:
		IConfig();
		IConfig(const IConfig& rhs);
	};
}
#endif