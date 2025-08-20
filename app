import React, {
  useState,
  useEffect,
  createContext,
  useContext,
  useMemo,
} from "react";
import {
  LineChart,
  Line,
  XAxis,
  YAxis,
  CartesianGrid,
  Tooltip,
  Legend,
  ResponsiveContainer,
} from "recharts";

// --- THEME & COLORS ---
const THEMES = {
  light: {
    background: "bg-gray-50",
    card: "bg-white",
    text: "text-gray-800",
    subtleText: "text-gray-500",
    borderColor: "border-gray-200",
    inputBg: "bg-gray-100",
  },
  dark: {
    background: "bg-gray-900",
    card: "bg-gray-800",
    text: "text-gray-100",
    subtleText: "text-gray-400",
    borderColor: "border-gray-700",
    inputBg: "bg-gray-700",
  },
};

const COLOR_PALETTES = {
  blue: {
    primary: "text-blue-500",
    primaryHex: "#3B82F6",
    accent: "bg-blue-500",
    toggle: "peer-checked:bg-blue-600",
  },
  green: {
    primary: "text-green-500",
    primaryHex: "#22C55E",
    accent: "bg-green-500",
    toggle: "peer-checked:bg-green-600",
  },
  purple: {
    primary: "text-purple-500",
    primaryHex: "#8B5CF6",
    accent: "bg-purple-500",
    toggle: "peer-checked:bg-purple-600",
  },
  orange: {
    primary: "text-orange-500",
    primaryHex: "#F97316",
    accent: "bg-orange-500",
    toggle: "peer-checked:bg-orange-600",
  },
};

const ThemeContext = createContext();
const useTheme = () => useContext(ThemeContext);

// --- DATA & CONTEXT ---
const HabitContext = createContext();

const initialHabits = [
  {
    id: "1",
    name: "Drink Water",
    history: {},
    activeDays: [0, 1, 2, 3, 4, 5, 6],
    icon: "💧",
    times: ["09:00", "12:00", "15:00", "18:00"],
  },
  {
    id: "2",
    name: "Read for 30 minutes",
    history: {},
    activeDays: [0, 1, 2, 3, 4, 5, 6],
    icon: "📚",
    times: ["21:00"],
  },
  {
    id: "3",
    name: "Go to the gym",
    history: {},
    activeDays: [1, 3, 5],
    icon: "🏃",
    times: ["17:30"],
  },
  {
    id: "4",
    name: "Sleep 8 hours",
    history: {},
    activeDays: [0, 1, 2, 3, 4, 5, 6],
    icon: "😴",
    times: ["23:00"],
  },
];

const HabitProvider = ({ children }) => {
  const [habits, setHabits] = useState([]);
  const today = new Date().toISOString().split("T")[0];

  useEffect(() => {
    const loadHabits = () => {
      try {
        const storedHabits = localStorage.getItem("habits");
        setHabits(storedHabits ? JSON.parse(storedHabits) : initialHabits);
      } catch (error) {
        console.error("Failed to load habits.", error);
        setHabits(initialHabits);
      }
    };
    loadHabits();
  }, []);

  useEffect(() => {
    if (habits.length > 0) {
      localStorage.setItem("habits", JSON.stringify(habits));
    }
  }, [habits]);

  const isHabitCompleted = (habit, time) => {
    const dateTimeKey = `${today}T${time}`;
    return habit.history[dateTimeKey] === true;
  };

  const toggleHabit = (id, time) => {
    const dateTimeKey = `${today}T${time}`;
    setHabits(
      habits.map((habit) => {
        if (habit.id === id) {
          const newHistory = {
            ...habit.history,
            [dateTimeKey]: !isHabitCompleted(habit, time),
          };
          return { ...habit, history: newHistory };
        }
        return habit;
      })
    );
  };

  const addHabit = (name, activeDays, icon, times) =>
    setHabits([
      ...habits,
      { id: String(Date.now()), name, history: {}, activeDays, icon, times },
    ]);
  const editHabit = (id, newName, activeDays, icon, times) =>
    setHabits(
      habits.map((h) =>
        h.id === id ? { ...h, name: newName, activeDays, icon, times } : h
      )
    );
  const deleteHabit = (id) => setHabits(habits.filter((h) => h.id !== id));
  const resetData = () => {
    setHabits(initialHabits);
    localStorage.removeItem("habits");
  };

  return (
    <HabitContext.Provider
      value={{
        habits,
        toggleHabit,
        addHabit,
        editHabit,
        deleteHabit,
        isHabitCompleted,
        resetData,
      }}
    >
      {children}
    </HabitContext.Provider>
  );
};

// --- ICONS ---
const HomeIcon = ({ className }) => (
  <svg
    className={className}
    xmlns="http://www.w3.org/2000/svg"
    fill="none"
    viewBox="0 0 24 24"
    stroke="currentColor"
  >
    <path
      strokeLinecap="round"
      strokeLinejoin="round"
      strokeWidth={2}
      d="M3 12l2-2m0 0l7-7 7 7M5 10v10a1 1 0 001 1h3m10-11l2 2m-2-2v10a1 1 0 01-1 1h-3m-6 0a1 1 0 001-1v-4a1 1 0 011-1h2a1 1 0 011 1v4a1 1 0 001 1m-6 0h6"
    />
  </svg>
);
const ListIcon = ({ className }) => (
  <svg
    className={className}
    xmlns="http://www.w3.org/2000/svg"
    fill="none"
    viewBox="0 0 24 24"
    stroke="currentColor"
  >
    <path
      strokeLinecap="round"
      strokeLinejoin="round"
      strokeWidth={2}
      d="M4 6h16M4 10h16M4 14h16M4 18h16"
    />
  </svg>
);
const ChartIcon = ({ className }) => (
  <svg
    className={className}
    xmlns="http://www.w3.org/2000/svg"
    fill="none"
    viewBox="0 0 24 24"
    stroke="currentColor"
  >
    <path
      strokeLinecap="round"
      strokeLinejoin="round"
      strokeWidth={2}
      d="M9 19v-6a2 2 0 00-2-2H5a2 2 0 00-2 2v6a2 2 0 002 2h2a2 2 0 002-2zm0 0V9a2 2 0 012-2h2a2 2 0 012 2v10m-6 0a2 2 0 002 2h2a2 2 0 002-2m0 0V5a2 2 0 012-2h2a2 2 0 012 2v14a2 2 0 01-2 2h-2a2 2 0 01-2-2z"
    />
  </svg>
);
const SettingsIcon = ({ className }) => (
  <svg
    className={className}
    xmlns="http://www.w3.org/2000/svg"
    fill="none"
    viewBox="0 0 24 24"
    stroke="currentColor"
  >
    <path
      strokeLinecap="round"
      strokeLinejoin="round"
      strokeWidth={2}
      d="M10.325 4.317c.426-1.756 2.924-1.756 3.35 0a1.724 1.724 0 002.573 1.066c1.543-.94 3.31.826 2.37 2.37a1.724 1.724 0 001.065 2.572c1.756.426 1.756 2.924 0 3.35a1.724 1.724 0 00-1.066 2.573c.94 1.543-.826 3.31-2.37 2.37a1.724 1.724 0 00-2.572 1.065c-.426 1.756-2.924 1.756-3.35 0a1.724 1.724 0 00-2.573-1.066c-1.543.94-3.31-.826-2.37-2.37a1.724 1.724 0 00-1.065-2.572c-1.756-.426-1.756-2.924 0-3.35a1.724 1.724 0 001.066-2.573c-.94-1.543.826-3.31 2.37-2.37.996.608 2.296.07 2.572-1.065z"
    />
    <path
      strokeLinecap="round"
      strokeLinejoin="round"
      strokeWidth={2}
      d="M15 12a3 3 0 11-6 0 3 3 0 016 0z"
    />
  </svg>
);

// --- COMPONENTS ---
const ProgressBar = ({ progress }) => {
  const { theme } = useTheme();
  return (
    <div
      className={`w-full h-2.5 rounded-full ${theme.inputBg} border ${theme.borderColor} overflow-hidden`}
    >
      <div
        className={`h-full rounded-full ${theme.accent}`}
        style={{ width: `${progress}%`, transition: "width 0.3s ease-in-out" }}
      />
    </div>
  );
};

const HabitItem = ({ habit, time }) => {
  const { theme } = useTheme();
  const { toggleHabit, isHabitCompleted } = useContext(HabitContext);
  const completed = isHabitCompleted(habit, time);

  return (
    <div
      onClick={() => toggleHabit(habit.id, time)}
      className={`flex items-center justify-between p-4 mb-3 rounded-lg border ${theme.borderColor} ${theme.card} cursor-pointer transition-all duration-200 hover:shadow-md`}
    >
      <div className="flex items-center">
        <span className="text-2xl mr-3">{habit.icon}</span>
        <div>
          <p
            className={`${theme.text} ${
              completed ? "line-through text-gray-400" : ""
            }`}
          >
            {habit.name}
          </p>
          <p className={`${theme.subtleText} text-sm`}>{time}</p>
        </div>
      </div>
      <div
        className={`w-6 h-6 rounded-full border-2 ${
          completed ? `${theme.accent} ${theme.borderColor}` : theme.borderColor
        } flex items-center justify-center transition-all duration-200`}
      >
        {completed && <span className="text-white text-sm">✓</span>}
      </div>
    </div>
  );
};

const motivationalQuotes = [
  "Success is the sum of small efforts, repeated day in and day out.",
  "Well done is better than well said.",
  "The secret of getting ahead is getting started.",
  "You are what you repeatedly do. Excellence, then, is not an act, but a habit.",
  "Consistency is the key to success.",
  "The journey of a thousand miles begins with a single step.",
  "Believe you can and you're halfway there.",
  "Don't watch the clock; do what it does. Keep going.",
  "The only way to do great work is to love what you do.",
  "Motivation is what gets you started. Habit is what keeps you going.",
  "Small progress is still progress.",
  "Discipline is the bridge between goals and accomplishment.",
  "Your future is created by what you do today, not tomorrow.",
  "It does not matter how slowly you go as long as you do not stop.",
  "Success doesn't come from what you do occasionally, it comes from what you do consistently.",
];

const CelebrationAnimation = ({ onAnimationEnd }) => {
  const { theme } = useTheme();
  const quote = useMemo(
    () =>
      motivationalQuotes[Math.floor(Math.random() * motivationalQuotes.length)],
    []
  );

  useEffect(() => {
    const timer = setTimeout(onAnimationEnd, 4000);
    return () => clearTimeout(timer);
  }, [onAnimationEnd]);

  return (
    <div className="fixed inset-0 bg-black bg-opacity-50 flex items-center justify-center z-50 animate-fade-in">
      <div
        className={`p-8 rounded-lg ${theme.card} text-center flex flex-col items-center shadow-2xl mx-4`}
      >
        <svg
          className="checkmark"
          xmlns="http://www.w3.org/2000/svg"
          viewBox="0 0 52 52"
        >
          <circle
            className="checkmark__circle"
            cx="26"
            cy="26"
            r="25"
            fill="none"
          />
          <path
            className="checkmark__check"
            fill="none"
            d="M14.1 27.2l7.1 7.2 16.7-16.8"
          />
        </svg>
        <p className={`mt-4 text-lg font-semibold ${theme.text}`}>{quote}</p>
      </div>
    </div>
  );
};

const ConfirmationModal = ({ title, message, onConfirm, onCancel }) => {
  const { theme } = useTheme();
  return (
    <div className="fixed inset-0 bg-black bg-opacity-50 flex items-center justify-center p-4 z-50">
      <div
        className={`${theme.card} ${theme.text} p-6 rounded-lg shadow-xl w-full max-w-sm`}
      >
        <h2 className="text-xl font-bold mb-2">{title}</h2>
        <p className={`${theme.subtleText} mb-6`}>{message}</p>
        <div className="flex justify-end space-x-3">
          <button
            onClick={onCancel}
            className={`px-4 py-2 rounded-md ${theme.inputBg} hover:opacity-80`}
          >
            Cancel
          </button>
          <button
            onClick={onConfirm}
            className="px-4 py-2 rounded-md bg-red-500 text-white hover:bg-red-600"
          >
            Confirm
          </button>
        </div>
      </div>
    </div>
  );
};

// --- SCREENS / PAGES ---
function HomeScreen() {
  const { habits, isHabitCompleted } = useContext(HabitContext);
  const { theme } = useTheme();
  const [showCelebration, setShowCelebration] = useState(false);
  const [currentTime, setCurrentTime] = useState(new Date());

  useEffect(() => {
    const timer = setInterval(() => setCurrentTime(new Date()), 60000); // Update every minute
    return () => clearInterval(timer);
  }, []);

  const currentDay = currentTime.getDay();
  const todaysHabits = habits.filter((h) => h.activeDays.includes(currentDay));
  const allTodaysTasks = useMemo(
    () =>
      todaysHabits
        .flatMap((habit) => habit.times.map((time) => ({ ...habit, time })))
        .sort((a, b) => a.time.localeCompare(b.time)),
    [todaysHabits]
  );

  const nextHabit = useMemo(() => {
    const now = `${currentTime
      .getHours()
      .toString()
      .padStart(2, "0")}:${currentTime
      .getMinutes()
      .toString()
      .padStart(2, "0")}`;
    return allTodaysTasks.find(
      (task) => task.time > now && !isHabitCompleted(task, task.time)
    );
  }, [allTodaysTasks, currentTime, isHabitCompleted]);

  const completedCount = allTodaysTasks.filter((task) =>
    isHabitCompleted(task, task.time)
  ).length;
  const totalCount = allTodaysTasks.length;
  const progress = totalCount > 0 ? (completedCount / totalCount) * 100 : 0;

  useEffect(() => {
    if (progress >= 100 && totalCount > 0) {
      setShowCelebration(true);
    }
  }, [progress, totalCount]);

  return (
    <div className="p-4 relative">
      {showCelebration && (
        <CelebrationAnimation
          onAnimationEnd={() => setShowCelebration(false)}
        />
      )}
      <header className="mb-6">
        <h1 className={`text-3xl font-bold ${theme.text}`}>Today's Habits</h1>
        <p className={`${theme.subtleText}`}>{currentTime.toDateString()}</p>
      </header>

      {nextHabit && (
        <div
          className={`p-5 rounded-lg border ${theme.borderColor} ${theme.card} mb-6`}
        >
          <h2 className={`text-lg font-semibold ${theme.text} mb-2`}>
            Next Up
          </h2>
          <div className="flex items-center">
            <span className="text-3xl mr-4">{nextHabit.icon}</span>
            <div>
              <p className={`${theme.text} font-bold`}>{nextHabit.name}</p>
              <p className={`${theme.primary} font-semibold`}>
                {nextHabit.time}
              </p>
            </div>
          </div>
        </div>
      )}

      <div
        className={`p-5 rounded-lg border ${theme.borderColor} ${theme.card} mb-6`}
      >
        <div className="flex justify-between items-center mb-2">
          <h2 className={`text-lg font-semibold ${theme.text}`}>Progress</h2>
          <span className={`font-bold text-xl ${theme.primary}`}>
            {Math.round(progress)}%
          </span>
        </div>
        <ProgressBar progress={progress} />
      </div>
      <div>
        {allTodaysTasks.length > 0 ? (
          allTodaysTasks.map((task, index) => (
            <HabitItem
              key={`${task.id}-${task.time}-${index}`}
              habit={task}
              time={task.time}
            />
          ))
        ) : (
          <div
            className={`text-center p-10 rounded-lg border-2 border-dashed ${theme.borderColor} ${theme.subtleText}`}
          >
            No habits scheduled for today.
          </div>
        )}
      </div>
    </div>
  );
}

function HabitsListScreen({ setEditingHabit }) {
  const { habits, deleteHabit } = useContext(HabitContext);
  const { theme } = useTheme();
  const dayLabels = ["S", "M", "T", "W", "T", "F", "S"];

  const calculateStreak = (habit) => {
    let streak = 0;
    for (let i = 0; i < 365; i++) {
      const d = new Date();
      d.setDate(d.getDate() - i);
      const dateString = d.toISOString().split("T")[0];
      if (habit.activeDays.includes(d.getDay())) {
        const allTasksDone = habit.times.every(
          (time) => habit.history[`${dateString}T${time}`]
        );
        if (allTasksDone) {
          streak++;
        } else {
          break;
        }
      }
    }
    return streak;
  };

  return (
    <div className="p-4 relative min-h-full">
      <header className="mb-6">
        <h1 className={`text-3xl font-bold ${theme.text}`}>Manage Habits</h1>
      </header>
      <div className="pb-20">
        {habits.map((item) => (
          <div
            key={item.id}
            className={`p-4 mb-3 rounded-lg border ${theme.borderColor} ${theme.card}`}
          >
            <div className="flex items-center justify-between">
              <div className="flex items-center">
                <span className="text-2xl mr-3">{item.icon}</span>
                <p className={`${theme.text}`}>{item.name}</p>
              </div>
              <div className="flex space-x-4">
                <button
                  onClick={() => setEditingHabit(item)}
                  className={`${theme.primary} font-semibold`}
                >
                  Edit
                </button>
                <button
                  onClick={() => deleteHabit(item.id)}
                  className="text-red-500 font-semibold"
                >
                  Delete
                </button>
              </div>
            </div>
            <div className="flex items-center justify-between mt-2">
              <div className="flex space-x-1">
                {dayLabels.map((day, index) => (
                  <span
                    key={index}
                    className={`text-xs font-bold ${
                      item.activeDays.includes(index)
                        ? theme.primary
                        : theme.subtleText
                    }`}
                  >
                    {day}
                  </span>
                ))}
              </div>
              <p className={`${theme.subtleText} text-sm`}>
                🔥 Streak: {calculateStreak(item)} days
              </p>
            </div>
          </div>
        ))}
      </div>
      <button
        onClick={() => setEditingHabit({})}
        className={`absolute right-6 bottom-20 w-14 h-14 ${theme.accent} text-white rounded-full text-3xl flex items-center justify-center shadow-lg hover:opacity-90 transition-opacity`}
      >
        +
      </button>
    </div>
  );
}

const habitIcons = ["💧", "📚", "🏃", "😴", "🧘", "🎨", "🎸", "💻", "🎯", "✅"];

function AddEditHabitModal({ habit, closeModal }) {
  const { addHabit, editHabit } = useContext(HabitContext);
  const [name, setName] = useState(habit ? habit.name : "");
  const [activeDays, setActiveDays] = useState(
    habit?.activeDays || [0, 1, 2, 3, 4, 5, 6]
  );
  const [icon, setIcon] = useState(habit?.icon || "🎯");
  const [times, setTimes] = useState(habit?.times || ["09:00"]);
  const [newTime, setNewTime] = useState("");
  const { theme } = useTheme();
  const isEditing = habit && habit.id;
  const dayLabels = ["S", "M", "T", "W", "T", "F", "S"];

  const toggleDay = (dayIndex) => {
    setActiveDays(
      activeDays.includes(dayIndex)
        ? activeDays.filter((d) => d !== dayIndex)
        : [...activeDays, dayIndex]
    );
  };

  const handleAddTime = () => {
    if (newTime && !times.includes(newTime)) {
      setTimes([...times, newTime].sort());
      setNewTime("");
    }
  };

  const removeTime = (timeToRemove) => {
    setTimes(times.filter((t) => t !== timeToRemove));
  };

  const handleSave = (e) => {
    e.preventDefault();
    if (
      name.trim().length === 0 ||
      activeDays.length === 0 ||
      times.length === 0
    )
      return;
    isEditing
      ? editHabit(habit.id, name, activeDays, icon, times)
      : addHabit(name, activeDays, icon, times);
    closeModal();
  };

  return (
    <div className="fixed inset-0 bg-black bg-opacity-50 flex items-center justify-center p-4 z-50">
      <div
        className={`${theme.card} ${theme.text} p-6 rounded-lg shadow-xl w-full max-w-md`}
      >
        <h2 className="text-2xl font-bold mb-4">
          {isEditing ? "Edit Habit" : "Add New Habit"}
        </h2>
        <form onSubmit={handleSave}>
          <input
            type="text"
            className={`w-full p-3 rounded-md border ${theme.borderColor} ${theme.inputBg} ${theme.text} focus:outline-none focus:ring-2 ${theme.primary} mb-4`}
            placeholder="e.g., Go for a run"
            value={name}
            onChange={(e) => setName(e.target.value)}
            autoFocus
          />
          <div className="mb-4">
            <p className={`mb-2 ${theme.subtleText}`}>Icon:</p>
            <div className="flex flex-wrap gap-2">
              {habitIcons.map((i) => (
                <button
                  type="button"
                  key={i}
                  onClick={() => setIcon(i)}
                  className={`w-10 h-10 text-2xl rounded-full transition-all ${
                    icon === i
                      ? `ring-2 ${theme.primary}`
                      : "opacity-50 hover:opacity-100"
                  }`}
                >
                  {i}
                </button>
              ))}
            </div>
          </div>
          <div className="mb-4">
            <p className={`mb-2 ${theme.subtleText}`}>Times:</p>
            <div className="flex items-center gap-2 mb-2">
              <input
                type="time"
                value={newTime}
                onChange={(e) => setNewTime(e.target.value)}
                className={`flex-grow p-2 rounded-md border ${theme.borderColor} ${theme.inputBg}`}
              />
              <button
                type="button"
                onClick={handleAddTime}
                className={`px-4 py-2 rounded-md ${theme.accent} text-white`}
              >
                Add
              </button>
            </div>
            <div className="flex flex-wrap gap-2">
              {times.map((t) => (
                <span
                  key={t}
                  className={`px-2 py-1 rounded-full ${theme.inputBg} text-sm flex items-center`}
                >
                  {t}{" "}
                  <button
                    type="button"
                    onClick={() => removeTime(t)}
                    className="ml-2 text-red-500"
                  >
                    ×
                  </button>
                </span>
              ))}
            </div>
          </div>
          <div className="mb-4">
            <p className={`mb-2 ${theme.subtleText}`}>Repeat on:</p>
            <div className="flex justify-between">
              {dayLabels.map((label, index) => (
                <button
                  type="button"
                  key={index}
                  onClick={() => toggleDay(index)}
                  className={`w-9 h-9 rounded-full font-bold transition-colors ${
                    activeDays.includes(index)
                      ? `${theme.accent} text-white`
                      : `${theme.inputBg}`
                  }`}
                >
                  {label}
                </button>
              ))}
            </div>
          </div>
          <div className="flex justify-end space-x-3">
            <button
              type="button"
              onClick={closeModal}
              className={`px-4 py-2 rounded-md ${theme.inputBg} hover:opacity-80`}
            >
              Cancel
            </button>
            <button
              type="submit"
              className={`px-4 py-2 rounded-md ${theme.accent} text-white hover:opacity-90`}
            >
              Save
            </button>
          </div>
        </form>
      </div>
    </div>
  );
}

const MonthlyStatsGrid = () => {
  const { habits } = useContext(HabitContext);
  const { theme } = useTheme();

  const data = useMemo(() => {
    const days = [];
    for (let i = 29; i >= 0; i--) {
      const d = new Date();
      d.setDate(d.getDate() - i);
      const dateString = d.toISOString().split("T")[0];
      const activeHabits = habits.filter((h) =>
        h.activeDays.includes(d.getDay())
      );
      const allTasks = activeHabits.flatMap((h) =>
        h.times.map((t) => ({ ...h, time: t }))
      );
      const completedCount = allTasks.reduce(
        (count, task) =>
          task.history[`${dateString}T${task.time}`] ? count + 1 : count,
        0
      );
      const percentage =
        allTasks.length > 0 ? (completedCount / allTasks.length) * 100 : 0;
      days.push({ date: d, percentage, hasHabits: allTasks.length > 0 });
    }
    return days;
  }, [habits]);

  const getColor = (percentage, hasHabits) => {
    if (!hasHabits) return `${theme.inputBg} opacity-50`;
    if (percentage >= 100) return "bg-green-500";
    if (percentage > 0) return "bg-orange-400";
    return theme.inputBg;
  };

  return (
    <div className={`${theme.card} p-4 rounded-lg border ${theme.borderColor}`}>
      <h3 className={`text-lg font-bold mb-4 ${theme.text}`}>Last 30 Days</h3>
      <div className="grid grid-cols-7 gap-2">
        {data.map(({ date, percentage, hasHabits }, index) => (
          <div key={index} className="flex flex-col items-center">
            <div
              className={`w-8 h-8 rounded-md ${getColor(
                percentage,
                hasHabits
              )} flex items-center justify-center text-white font-bold text-xs`}
            >
              {hasHabits ? Math.round(percentage) : "-"}
            </div>
            <span className={`text-xs mt-1 ${theme.subtleText}`}>
              {date.getDate()}
            </span>
          </div>
        ))}
      </div>
    </div>
  );
};

function StatsScreen() {
  const { habits } = useContext(HabitContext);
  const { theme, isDark } = useTheme();

  const getWeekData = () => {
    const data = [];
    for (let i = 6; i >= 0; i--) {
      const d = new Date();
      d.setDate(d.getDate() - i);
      const activeHabits = habits.filter((h) =>
        h.activeDays.includes(d.getDay())
      );
      const allTasks = activeHabits.flatMap((h) =>
        h.times.map((t) => ({ ...h, time: t }))
      );
      const completed = allTasks.reduce(
        (count, task) =>
          task.history[`${d.toISOString().split("T")[0]}T${task.time}`]
            ? count + 1
            : count,
        0
      );
      data.push({
        name: d.toLocaleDateString("en-US", { weekday: "short" }),
        completed,
      });
    }
    return data;
  };

  return (
    <div className="p-4 space-y-6">
      <header>
        <h1 className={`text-3xl font-bold ${theme.text}`}>Weekly Progress</h1>
      </header>
      <div
        className={`${theme.card} p-4 rounded-lg border ${theme.borderColor} h-72`}
      >
        {habits.length > 0 ? (
          <ResponsiveContainer width="100%" height="100%">
            <LineChart
              data={getWeekData()}
              margin={{ top: 5, right: 20, left: -10, bottom: 5 }}
            >
              <CartesianGrid
                strokeDasharray="3 3"
                stroke={isDark ? "#4A5568" : "#E2E8F0"}
              />
              <XAxis dataKey="name" stroke={isDark ? "#A0AEC0" : "#4A5568"} />
              <YAxis
                allowDecimals={false}
                stroke={isDark ? "#A0AEC0" : "#4A5568"}
              />
              <Tooltip
                contentStyle={{
                  backgroundColor: isDark ? "#2D3748" : "#FFFFFF",
                  border: `1px solid ${isDark ? "#4A5568" : "#E2E8F0"}`,
                }}
              />
              <Line
                type="monotone"
                dataKey="completed"
                stroke={theme.primaryHex}
                strokeWidth={2}
                activeDot={{ r: 8 }}
              />
            </LineChart>
          </ResponsiveContainer>
        ) : (
          <div className="flex items-center justify-center h-full">
            <p className={`${theme.subtleText}`}>No habit data to display.</p>
          </div>
        )}
      </div>
      <MonthlyStatsGrid />
    </div>
  );
}

const SettingsToggle = ({ label, description, enabled, onToggle }) => {
  const { theme } = useTheme();
  return (
    <div
      className={`p-4 rounded-lg border ${theme.borderColor} ${theme.card} mb-4`}
    >
      <div className="flex justify-between items-center">
        <span className={`text-lg ${theme.text}`}>{label}</span>
        <label className="relative inline-flex items-center cursor-pointer">
          <input
            type="checkbox"
            className="sr-only peer"
            checked={enabled}
            onChange={onToggle}
          />
          <div
            className={`w-11 h-6 bg-gray-200 rounded-full peer dark:bg-gray-700 peer-checked:after:translate-x-full after:absolute after:top-0.5 after:left-[2px] after:bg-white after:border after:rounded-full after:h-5 after:w-5 after:transition-all ${theme.toggle}`}
          ></div>
        </label>
      </div>
      {description && (
        <p className={`text-sm mt-2 ${theme.subtleText}`}>{description}</p>
      )}
    </div>
  );
};

function SettingsScreen({ setColorTheme }) {
  const { isDark, setIsDark, theme } = useTheme();
  const [notificationsEnabled, setNotificationsEnabled] = useState(
    Notification.permission === "granted"
  );
  const [showResetConfirm, setShowResetConfirm] = useState(false);
  const { resetData } = useContext(HabitContext);

  const handleNotificationToggle = () => {
    if (Notification.permission === "granted") {
      // This is a mock toggle; in a real app, you'd manage subscription state.
      setNotificationsEnabled(!notificationsEnabled);
    } else if (Notification.permission !== "denied") {
      Notification.requestPermission().then((permission) => {
        if (permission === "granted") {
          setNotificationsEnabled(true);
        }
      });
    }
  };

  const handleReset = () => {
    resetData();
    setShowResetConfirm(false);
  };

  return (
    <div className="p-4">
      {showResetConfirm && (
        <ConfirmationModal
          title="Reset Data"
          message="Are you sure? All your habit history will be permanently deleted."
          onConfirm={handleReset}
          onCancel={() => setShowResetConfirm(false)}
        />
      )}
      <header className="mb-6">
        <h1 className={`text-3xl font-bold`}>Settings</h1>
      </header>
      <SettingsToggle
        label="Dark Mode"
        enabled={isDark}
        onToggle={() => setIsDark(!isDark)}
      />
      <SettingsToggle
        label="Habit Reminders"
        description="Allow browser notifications for upcoming habits."
        enabled={notificationsEnabled}
        onToggle={handleNotificationToggle}
      />

      <div
        className={`p-4 rounded-lg border ${theme.borderColor} ${theme.card} mb-4`}
      >
        <h3 className={`text-lg mb-3 ${theme.text}`}>Theme Color</h3>
        <div className="flex justify-around">
          {Object.keys(COLOR_PALETTES).map((color) => (
            <button
              key={color}
              onClick={() => setColorTheme(color)}
              className={`w-10 h-10 rounded-full ${
                COLOR_PALETTES[color].accent
              } border-2 ${
                theme.borderColor
              } focus:outline-none focus:ring-2 ring-offset-2 ${
                theme.background === "bg-gray-900"
                  ? "ring-offset-gray-900"
                  : "ring-offset-gray-50"
              }`}
            ></button>
          ))}
        </div>
      </div>

      <div
        className={`p-4 rounded-lg border border-red-500/50 ${theme.card} mb-4`}
      >
        <button
          onClick={() => setShowResetConfirm(true)}
          className="w-full text-center text-red-500 font-semibold"
        >
          Reset All Data
        </button>
      </div>
    </div>
  );
}

// --- NAVIGATION & MAIN APP ---
const TABS = {
  Home: HomeIcon,
  Habits: ListIcon,
  Stats: ChartIcon,
  Settings: SettingsIcon,
};

export default function App() {
  const [isDark, setIsDark] = useState(false);
  const [colorTheme, setColorTheme] = useState("blue");
  const [activeTab, setActiveTab] = useState("Home");
  const [editingHabit, setEditingHabit] = useState(null);

  useEffect(() => {
    const storedTheme = localStorage.getItem("theme");
    const storedColor = localStorage.getItem("colorTheme");
    const prefersDark = window.matchMedia(
      "(prefers-color-scheme: dark)"
    ).matches;
    setIsDark(storedTheme ? storedTheme === "dark" : prefersDark);
    if (storedColor) setColorTheme(storedColor);
  }, []);

  useEffect(() => {
    localStorage.setItem("theme", isDark ? "dark" : "light");
    document.documentElement.classList.toggle("dark", isDark);
  }, [isDark]);

  useEffect(() => {
    localStorage.setItem("colorTheme", colorTheme);
  }, [colorTheme]);

  // Notification logic
  const { habits } = useContext(HabitContext) || { habits: [] };
  useEffect(() => {
    if (Notification.permission !== "granted") return;

    const checkNotifications = () => {
      const now = new Date();
      const currentTime = `${now.getHours().toString().padStart(2, "0")}:${now
        .getMinutes()
        .toString()
        .padStart(2, "0")}`;
      const currentDay = now.getDay();

      habits.forEach((habit) => {
        if (
          habit.activeDays.includes(currentDay) &&
          habit.times.includes(currentTime)
        ) {
          new Notification(`Time for your habit: ${habit.name}`, {
            body: `Don't forget to complete your habit!`,
            icon: "data:image/svg+xml,<svg xmlns=%22http://www.w3.org/2000/svg%22 viewBox=%220 0 100 100%22><text y=%22.9em%22 font-size=%2290%22>${habit.icon}</text></svg>",
          });
        }
      });
    };

    const interval = setInterval(checkNotifications, 60000); // Check every minute
    return () => clearInterval(interval);
  }, [habits]);

  const theme = {
    ...(isDark ? THEMES.dark : THEMES.light),
    ...COLOR_PALETTES[colorTheme],
  };
  const themeValue = { theme, isDark, setIsDark };

  const renderContent = () => {
    switch (activeTab) {
      case "Home":
        return <HomeScreen />;
      case "Habits":
        return <HabitsListScreen setEditingHabit={setEditingHabit} />;
      case "Stats":
        return <StatsScreen />;
      case "Settings":
        return <SettingsScreen setColorTheme={setColorTheme} />;
      default:
        return <HomeScreen />;
    }
  };

  return (
    <ThemeContext.Provider value={themeValue}>
      <HabitProvider>
        <style>{`
          .checkmark__circle { stroke-dasharray: 166; stroke-dashoffset: 166; stroke-width: 2; stroke-miterlimit: 10; stroke: #4CAF50; fill: none; animation: stroke 0.6s cubic-bezier(0.65, 0, 0.45, 1) forwards; }
          .checkmark { width: 80px; height: 80px; border-radius: 50%; display: block; stroke-width: 3; stroke: #fff; stroke-miterlimit: 10; margin: auto; box-shadow: inset 0px 0px 0px #4CAF50; animation: fill .4s ease-in-out .4s forwards, scale .3s ease-in-out .9s both; }
          .checkmark__check { transform-origin: 50% 50%; stroke-dasharray: 48; stroke-dashoffset: 48; animation: stroke 0.3s cubic-bezier(0.65, 0, 0.45, 1) 0.8s forwards; }
          @keyframes stroke { 100% { stroke-dashoffset: 0; } }
          @keyframes scale { 0%, 100% { transform: none; } 50% { transform: scale3d(1.1, 1.1, 1); } }
          @keyframes fill { 100% { box-shadow: inset 0px 0px 0px 40px #4CAF50; } }
          @keyframes fade-in { from { opacity: 0; } to { opacity: 1; } }
          .animate-fade-in { animation: fade-in 0.3s ease-out; }
        `}</style>
        <div
          className={`w-full min-h-screen font-sans ${theme.background} ${theme.text} transition-colors duration-300`}
        >
          <main className="pb-20">{renderContent()}</main>
          {editingHabit && (
            <AddEditHabitModal
              habit={editingHabit}
              closeModal={() => setEditingHabit(null)}
            />
          )}
          <nav
            className={`fixed bottom-0 left-0 right-0 h-16 ${theme.card} border-t ${theme.borderColor} flex justify-around items-center`}
          >
            {Object.keys(TABS).map((tab) => {
              const Icon = TABS[tab];
              return (
                <button
                  key={tab}
                  onClick={() => setActiveTab(tab)}
                  className={`flex flex-col items-center justify-center h-full w-16 transition-colors duration-200 ${
                    activeTab === tab ? theme.primary : theme.subtleText
                  }`}
                >
                  <Icon className="w-6 h-6" />
                  <span className="text-xs mt-1">{tab}</span>
                </button>
              );
            })}
          </nav>
        </div>
      </HabitProvider>
    </ThemeContext.Provider>
  );
}
