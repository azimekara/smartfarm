using Entities.Concrete;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Abstract
{
    public interface IRoofActivityService
    {
        Task<List<RoofActivity>> GetRoofActivities();
        Task<RoofActivity> GetEndActivity();
        void AddActivity(RoofActivity roofActivity);
    }
}
